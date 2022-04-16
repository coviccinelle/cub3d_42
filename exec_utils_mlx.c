/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:47:26 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/16 11:50:25 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->img[i].img = mlx_xpm_file_to_image(game->mlx.ptr, \
		game->img[i].path, &game->img[i].width, &game->img[i].height);
		if (!(game->img[i].img))
			ft_puterror_exit(game->img[i].path, game);
		game->img[i].add = mlx_get_data_addr(game->img[i].img, \
		&game->img[i].bits_per_pixel, &game->img[i].line_length, \
		&game->img[i].endian);
	}
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx.addr + (y * game->mlx.line_length + x * \
	(game->mlx.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_color(int start_y, int end_y, unsigned int color, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = start_y - 1;
	while (++j <= end_y)
	{
		i = -1;
		while (++i <= game->win_width)
			my_pixel_put(game, i, j, color);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i <= game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
	}
}
