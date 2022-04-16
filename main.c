/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:51:38 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/16 15:51:11 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_background(t_game *game)
{
	draw_color(0, game->win_height / 2, game->draw.floor, game);
	draw_color(game->win_height / 2, game->win_height, \
	game->draw.ceiling, game);
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	print_background(game);
	while (x < game->win_width)
	{
		raycasting_initialize(game, x);
		raycasting_initialize2(game);
		check_when_ray_hits_wall(game);
		draw_calculations(game);
		draw_walls(game, x);
		game->ray.hit = 0;
		x++;
	}
}

int	render_next_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	if (game->over == 1)
		exit_free(game);
	player_moves(game);
	raycasting(game);
	return (0);
}

void	run_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		ft_puterror_exit("mlx ptr init failed", game);
	mlx_get_screen_size(game->mlx.ptr, &(game->win_width), &(game->win_height));
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->win_width, \
	game->win_height, "Cub3D");
	if (!game->mlx.win)
		ft_puterror_exit("mlx win init failed", game);
	mlx_loop_hook(game->mlx.ptr, render_next_frame, game);
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, ft_key_hook, game);
	mlx_hook(game->mlx.win, KeyRelease, KeyReleaseMask, ft_key_unhook, game);
	mlx_hook(game->mlx.win, ClientMessage, LeaveWindowMask, exit_free, game);
	game->mlx.img = mlx_new_image(game->mlx.ptr, game->win_width, \
	game->win_height);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, \
	&game->mlx.bits_per_pixel, &game->mlx.line_length, &game->mlx.endian);
	load_textures(game);
	mlx_loop(game->mlx.ptr);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	init_struct(&game);
	if (ac != 2)
		return (EXIT_FAILURE);
	if (!parsing(ac, av, &game))
		return (EXIT_FAILURE);
	init_player(&game);
	run_mlx(&game);
	free_map(&game);
	free_textures(&game);
	return (EXIT_SUCCESS);
}
	//print_info(&game);
