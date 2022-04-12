/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_hook_and_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:23:55 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 11:20:22 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_FORWARD)
		game->player.move_forward = 1;
	if (keycode == KEY_BACKWARD)
		game->player.move_backward = 1;
	if (keycode == KEY_RIGHT)
		game->player.move_right = 1;
	if (keycode == KEY_LEFT)
		game->player.move_left = 1;
	if (keycode == KEY_TURN_LEFT)
		game->player.look_left = 1;
	if (keycode == KEY_TURN_RIGHT)
		game->player.look_right = 1;
	if (keycode == KEY_ESCAPE)
		game->over = 1;
	return (0);
}

int	ft_key_unhook(int keycode, t_game *game)
{
	if (keycode == KEY_FORWARD)
		game->player.move_forward = 0;
	if (keycode == KEY_BACKWARD)
		game->player.move_backward = 0;
	if (keycode == KEY_RIGHT)
		game->player.move_right = 0;
	if (keycode == KEY_LEFT)
		game->player.move_left = 0;
	if (keycode == KEY_TURN_LEFT)
		game->player.look_left = 0;
	if (keycode == KEY_TURN_RIGHT)
		game->player.look_right = 0;
	if (keycode == KEY_ESCAPE)
		game->over = 0;
	return (0);
}
