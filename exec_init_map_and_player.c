/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_map_and_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:26:23 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 11:25:40 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* sets player and camera structs etc to null to avoid garbage values 
// and unitialized values messages */
void	init_struct(t_game *game)
{
	int	i;

	i = -1;
	game->player.move_forward = 0;
	game->player.move_backward = 0;
	game->player.move_right = 0;
	game->player.move_left = 0;
	game->player.look_right = 0;
	game->player.look_left = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->camera.plane_x = 0;
	game->camera.plane_y = 0;
	game->over = 0;
	game->nb_p = 0;
	game->mlx.ptr = 0;
	game->mlx.win = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->ray.hit = 0;
	while (++i < 4)
		game->img[i].path = 0;
}

/*
pos_x and pos_y represent the position vector of the player, dir_x and dir_y 
represent the direction of the player, and plane_x and plane_y the camera plane
 of the player. 
FOV is 2 * atan(0.66/1.0)=66°is perfect for a first person shooter game
Camera->plane_x : left side of the screen will get coordinate -1, the center 
of the screen gets coordinate 0, and the right side of the screen gets 
coordinate 1.
Camera->plane_y : upper side of the screen will get coordinate -1, the center
of the screen gets coordinate 0, and the down side of the screen gets
coordinate 1.
So : 
North means y = -1
South means y = 1;
West means x = -1;
East means x = 1;
Thanks to this the direction of the ray will be calculated (sum of the 
direction vector, and a part of the plane vector. This has to be done 
both for the x and y coordinate of the vector (since adding two vectors 
is adding their x-coordinates, and adding their y-coordinates)
Later on when rotating around with the input keys, the values of dir
 and plane will be changed, but they'll always remain perpendicular and 
 keep the same length.
*/

void	init_player(t_game *game)
{
	if (game->player.start_dir == 'N')
	{
		game->player.dir_y = -1;
		game->camera.plane_x = 0.66;
	}
	if (game->player.start_dir == 'S')
	{
		game->player.dir_y = 1;
		game->camera.plane_x = -0.66;
	}
	if (game->player.start_dir == 'W')
	{
		game->player.dir_x = -1;
		game->camera.plane_y = -0.66;
	}
	if (game->player.start_dir == 'E')
	{
		game->player.dir_x = 1;
		game->camera.plane_y = 0.66;
	}
}
