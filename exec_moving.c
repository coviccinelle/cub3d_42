/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:29:01 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/11 13:01:09 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mv(int i)
{
	if (i == '1')
		return (0);
	return (1);
}

void	move_right_left(t_game *game)
{
	if (game->player.move_right == 1)
	{
		if (mv(game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x - \
		game->player.dir_y * MOVING_SPEED)]))
			game->player.pos_x -= game->player.dir_y * MOVING_SPEED;
		if (mv(game->map[(int)(game->player.pos_y + game->player.dir_x * \
		MOVING_SPEED)][(int)(game->player.pos_x)]))
			game->player.pos_y += game->player.dir_x * MOVING_SPEED;
	}
	if (game->player.move_left == 1)
	{
		if (mv(game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x + \
		game->player.dir_y * MOVING_SPEED)]))
			game->player.pos_x += game->player.dir_y * MOVING_SPEED;
		if (mv(game->map[(int)(game->player.pos_y - game->player.dir_x * \
		MOVING_SPEED)][(int)(game->player.pos_x)]))
			game->player.pos_y -= game->player.dir_x * MOVING_SPEED;
	}
}

void	look_right(t_game *game)
{
	double	tmp;

	tmp = 0;
	if (game->player.look_right == 1)
	{
		tmp = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROTATION_SPEED) - \
		game->player.dir_y * sin(-ROTATION_SPEED);
		game->player.dir_y = tmp * sin(-ROTATION_SPEED) + game->player.dir_y * \
		cos(-ROTATION_SPEED);
		tmp = game->camera.plane_x;
		game->camera.plane_x = game->camera.plane_x * cos(-ROTATION_SPEED) - \
		game->camera.plane_y * sin(-ROTATION_SPEED);
		game->camera.plane_y = tmp * sin(-ROTATION_SPEED) + \
		game->camera.plane_y * cos(-ROTATION_SPEED);
	}
}

void	look_left(t_game *game)
{
	double	tmp;

	tmp = 0;
	if (game->player.look_left == 1)
	{
		tmp = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROTATION_SPEED) - \
		game->player.dir_y * sin(ROTATION_SPEED);
		game->player.dir_y = tmp * sin(ROTATION_SPEED) + game->player.dir_y * \
		cos(ROTATION_SPEED);
		tmp = game->camera.plane_x;
		game->camera.plane_x = game->camera.plane_x * cos(ROTATION_SPEED) - \
		game->camera.plane_y * sin(ROTATION_SPEED);
		game->camera.plane_y = tmp * sin(ROTATION_SPEED) + \
		game->camera.plane_y * cos(ROTATION_SPEED);
	}
}

void	player_moves(t_game *game)
{
	if (game->player.move_forward == 1)
	{
		if (mv(game->map[(int)game->player.pos_y][(int)(game->player.pos_x + \
		game->player.dir_x * MOVING_SPEED)]))
			game->player.pos_x += game->player.dir_x * MOVING_SPEED;
		if (mv(game->map[(int)(game->player.pos_y + game->player.dir_y * \
		MOVING_SPEED)][(int)(game->player.pos_x)]))
			game->player.pos_y += game->player.dir_y * MOVING_SPEED;
	}
	if (game->player.move_backward == 1)
	{
		if (mv(game->map[(int)game->player.pos_y][(int)(game->player.pos_x - \
		game->player.dir_x * MOVING_SPEED)]))
			game->player.pos_x -= game->player.dir_x * MOVING_SPEED;
		if (mv(game->map[(int)(game->player.pos_y - game->player.dir_y * \
		MOVING_SPEED)][(int)(game->player.pos_x)]))
			game->player.pos_y -= game->player.dir_y * MOVING_SPEED;
	}
	move_right_left(game);
	look_right(game);
	look_left(game);
}
