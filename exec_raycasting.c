/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:40:08 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/11 12:40:50 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_initialize(t_game *game, int x)
{
	game->camera.pos_plane = 2 * x / (double)game->win_width - 1;
	game->ray.dir_x = game->player.dir_x + game->camera.plane_x * \
	game->camera.pos_plane;
	game->ray.dir_y = game->player.dir_y + game->camera.plane_y * \
	game->camera.pos_plane;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	if (game->ray.dir_x == 0)
		game->ray.delta_dist_x = 10000;
	else
	{
		if (game->ray.dir_x == 0)
			game->ray.delta_dist_x = 1;
		else
			game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	}
	if (game->ray.dir_y == 0)
		game->ray.delta_dist_y = 10000;
	else
	{
		if (game->ray.dir_y == 0)
			game->ray.delta_dist_y = 1;
		else
			game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
	}
}

/*
side_dist_x is the distance from the ray starting position to the first side 
to the left, if the ray direciton has a positive x-component the first side
to the right is used instead.
For these values, the integer value map_x is used and the real position
subtracted from it, and 1.0 is added in some of the cases depending if the 
side to the left or right, of the top or the bottom is used. 
Then you get the perpendicular distance to this side, so multiply it with 
delta_dist_x or delta_dist_y to get the real Euclidean distance. */

void	raycasting_initialize2(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x) * \
		game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x) * \
		game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y) * \
		game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y) * \
		game->ray.delta_dist_y;
	}
}

/*
To find the first wall that a ray encounters on its way, you have to let 
it start at the player's position, and then all the time, check whether 
or not the ray is inside a wall. 
a computer can only check a finite number of positions on the ray so if 
the ray position is not in a wall, 
you have to trace it further : Keep doing this until finally a wall is hit. 
If it's inside a wall (hit), then the loop can stop 
and then we can calculate the distance of this hit point to the player, and 
use this distance to calculate how high this wall has to be drawn on the screen:
the further away the wall, the smaller it's on screen, and the closer, the 
higher it appears to be.
*/
//side_dist_x : real euclidian distance
//ray.delta_dist_x :
//ray.map_x :
//ray.y_step : 1 ou -1 selon si la ligne "monte" ou "descend". calcule en 
//fonction de xraydir (aka la direction du player + la camera plane a 66 
//degres + la camera pos plane de ...).
/*side :When the ray has hit a wall, the loop ends, and then we'll know 
//whether an x-side or y-side of a wall was hit in the variable "side", 
//and what wall was hit with map_x and map_y.
We won't know exactly where the wall was hit however, but that's not needed 
//in this case because we won't use textured walls for now.*/

void	check_when_ray_hits_wall(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

//game side:
//distwall:
//linesize
//line start
//line end
/*
We don't use the Euclidean distance to the point representing player, 
but instead the distance to the camera plane (or, the distance of the point 
projected on the camera direction to the player),
to avoid the fisheye effect. The fisheye effect is an effect you see if you 
use the real distance, where all the walls become rounded, 
and can make you sick if you rotate.
depending on what number the wall that was hit has, a color is chosen. 
If an y-side was hit, the color is made darker, this gives a nicer effec
*/
void	draw_calculations(t_game *game)
{
	if (game->ray.side == 0)
		game->dist_wall = (game->ray.map_x - \
		game->player.pos_x + (1 - game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->dist_wall = (game->ray.map_y - game->player.pos_y + \
		(1 - game->ray.step_y) / 2) / game->ray.dir_y;
	game->draw.line_size = (int)(game->win_height / game->dist_wall);
	game->draw.line_start = -game->draw.line_size / 2 + game->win_height / 2;
	if (game->draw.line_start < 0)
		game->draw.line_start = 0;
	game->draw.line_end = game->draw.line_size / 2 + game->win_height / 2;
	if (game->draw.line_end >= game->win_height)
		game->draw.line_end = game->win_height - 1;
}
