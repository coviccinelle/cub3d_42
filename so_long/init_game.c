/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:31:24 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 11:24:48 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->window = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->nb_c = 0;
	game->nb_e = 0;
	game->nb_p = 0;
	game->img_backgr = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_coll = NULL;
	game->img_exit = NULL;
	game->img_width = 0;
	game->img_height = 0;
	game->moves = 0;
}

void	file_to_image(t_game *game)
{
	int		*w;
	int		*h;

	w = &game->img_width;
	h = &game->img_height;
	game->img_backgr = mlx_xpm_file_to_image(game->mlx_ptr, BACKGR, w, h);
	if (!game->img_backgr)
		error("Error\nMlx_xpm_file_to_image failed\n", game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, w, h);
	if (!game->img_wall)
		error("Error\nMlx_xpm_file_to_image failed\n", game);
	game->img_coll = mlx_xpm_file_to_image(game->mlx_ptr, COLL, w, h);
	if (!game->img_coll)
		error("Error\nMlx_xpm_file_to_image failed\n", game);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, w, h);
	if (!game->img_exit)
		error("Error\nMlx_xpm_file_to_image failed\n", game);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, w, h);
	if (!game->img_player)
		error("Error\nMlx_xpm_file_to_image failed\n", game);
}

void	init_game(t_game *game)
{
	int		w;
	int		h;

	w = game->map_width;
	h = game->map_height;
	game->img_width = 64;
	game->img_height = 64;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error("Error\nMlx_init failed\n", game);
	game->window = mlx_new_window(game->mlx_ptr, w * 64, h * 64, "so_long");
	if (!game->window)
		error("Error\nMlx_new_window failed\n", game);
	file_to_image(game);
}
