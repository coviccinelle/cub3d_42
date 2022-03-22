/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:28:19 by mloubet           #+#    #+#             */
/*   Updated: 2022/03/21 18:38:52 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_put(t_img *i, int x, int y, int color)
{
	*(unsigned int *)(i->data + (y * i->line_len + x
				* (i->bits_per_pixel / 8))) = color;
}

void	draw_texture(int x, int y, t_img *img, t_game *game)
{
	unsigned int	color;
	int				i;
	int				j;
	int				x_bis;
	int				y_bis;

	j = -1;
	while (++j < game->bpp)
	{
		i = -1;
		y_bis = (((float)j / (float)game->bpp) * img->width);
		while (++i < game->bpp)
		{
			x_bis = (((float)i / (float)game->bpp) * img->height);
			color = pixel_color(x_bis, y_bis, img);
			if (color != 0xFF000000)
				my_put(&(game->img), i + x, j + y, color);
		}
	}
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	draw_color(int startx, int starty, int x, int y, unsigned int color_c , t_game *game)
{
	int				i;
	int				j;

	i = startx -1;
	j = starty -1;
	while (++j <= y)
	{
		i = startx - 1;
		while (++i <= x)
			my_put(&(game->img), i , j, color_c);
	}
}

void	player_orientation(t_game *game, int x_win, int y_win)
{
	if (game->player.orientation_x == 1
		|| game->player.orientation_x == 0)
		draw_texture(x_win, y_win, &game->player_right, game);
	else if (game->player.orientation_x == -1)
		draw_texture(x_win, y_win, &game->player_left, game);
	if (game->player.orientation_y == 1)
		draw_texture(x_win, y_win, &game->player_down, game);
	else if (game->player.orientation_y == -1)
		draw_texture(x_win, y_win, &game->player_up, game);
}

int	draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] != '1')
				draw_texture(x * game->bpp, y * game->bpp, &game->ground, game);
			if (game->map[y][x] == 'C')
				draw_texture(x * game->bpp,
					y * game->bpp, &game->collectible, game);
			else if (game->map[y][x] == 'P')
				player_orientation(game, x * game->bpp, y * game->bpp);
			else if (game->map[y][x] == '1')
				draw_texture(x * game->bpp, y * game->bpp, &game->wall, game);
			else if (game->map[y][x] == 'E')
				draw_texture(x * game->bpp, y * game->bpp, &game->exit, game);
		}
	}
	return (1);
}
