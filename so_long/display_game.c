/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:25:44 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/12 12:18:16 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(int x, int y, t_game *game)
{
	char	pos;
	void	*mlx;
	void	*window;

	pos = game->map[y][x];
	mlx = game->mlx_ptr;
	window = game->window;
	if (pos == '0')
		mlx_put_image_to_window(mlx, window, game->img_backgr, x * 64, y * 64);
	if (pos == '1')
		mlx_put_image_to_window(mlx, window, game->img_wall, x * 64, y * 64);
	if (pos == 'P')
		mlx_put_image_to_window(mlx, window, game->img_player, x * 64, y * 64);
	if (pos == 'C')
		mlx_put_image_to_window(mlx, window, game->img_coll, x * 64, y * 64);
	if (pos == 'E')
		mlx_put_image_to_window(mlx, window, game->img_exit, x * 64, y * 64);
}

int	images_to_window(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (y++ < game->map_height - 1)
	{
		x = -1;
		while (x++ < game->map_width - 1)
			put_image(x, y, game);
	}
	return (0);
}

int	key_events(int keypressed, t_game *game)
{
	char		next_p;
	static int	nb_move;

	if (keypressed == ESC || keypressed == W || keypressed == A
		|| keypressed == S || keypressed == D)
	{
		next_p = set_next_p(keypressed, game);
		if (next_p != '1')
		{
			if (!is_exit(next_p, game))
			{
				game->map[game->player_y][game->player_x] = '0';
				mouvement(next_p, keypressed, game);
				game->map[game->player_y][game->player_x] = 'P';
				nb_move++;
				printf("Number of steps : %d\n", nb_move);
			}
		}
	}
	return (0);
}

int	close_x_exit(t_game *game)
{
	ft_exit(game, 1);
	return (1);
}

void	display_game(t_game game)
{
	mlx_loop_hook(game.mlx_ptr, &images_to_window, &game);
	mlx_key_hook(game.window, &key_events, &game);
	mlx_hook(game.window, 17, 0, &close_x_exit, &game);
	mlx_loop(game.mlx_ptr);
}
