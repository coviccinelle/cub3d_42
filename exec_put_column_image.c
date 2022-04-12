/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_put_column_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:35:20 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 11:19:51 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// N 0
// S 1
// W 2
// E 3
int	which_wall_tex(t_game *game)
{
	int	img;

	img = 0;
	if (game->ray.side == 1 && game->ray.dir_y > 0)
		img = 0;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		img = 1;
	if (game->ray.side == 0 && game->ray.dir_x < 0)
		img = 2;
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		img = 3;
	return (img);
}

void	texture_calculation(t_game *game, double *step, double *texpos_x, \
int id)
{
	if (game->ray.side == 0)
		game->wall_hit = game->player.pos_y + game->dist_wall * game->ray.dir_y;
	else
		game->wall_hit = game->player.pos_x + game->dist_wall * game->ray.dir_x;
	game->wall_hit -= floor(game->wall_hit);
	game->draw.x_texture = (int)(game->wall_hit * \
	(double)(game->img[id].width));
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		game->draw.x_texture = game->img[id].width - game->draw.x_texture - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		game->draw.x_texture = game->img[id].width - game->draw.x_texture - 1;
	*step = 1.0 * game->img[id].height / game->draw.line_size;
	*texpos_x = (game->draw.line_start - game->win_height / 2 + \
	game->draw.line_size / 2) * (*step);
}

void	draw_walls(t_game *game, int x)
{
	int		y;
	double	step;
	double	texpos_x;
	int		id;

	y = game->draw.line_start;
	id = which_wall_tex(game);
	texture_calculation(game, &step, &texpos_x, id);
	while (y < game->draw.line_end)
	{
		game->draw.y_texture = (int)texpos_x & (game->img[id].height - 1);
		texpos_x += step;
		*(unsigned int *)(game->mlx.addr + (y * game->mlx.line_length + x * 4)) \
		= *(unsigned int *)(game->img[id].add + game->draw.y_texture * \
		game->img[id].line_length + game->draw.x_texture * 4);
		y++;
	}
}
