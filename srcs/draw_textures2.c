/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:28:19 by mloubet           #+#    #+#             */
/*   Updated: 2022/03/21 17:00:59 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *game, t_img *img, char *path)
{
	img->xpm = mlx_xpm_file_to_image(game->mlx.ptr, path,
			&(img->width), &(img->height));
	if (!img->xpm)
	{
		printf("Error\nImage not found : %s\n", path);
		free_sprites(game);
		free_gnl(&game->map);
		free(game->map);
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
		exit(0);
	}
	if (img->xpm)
		img->data = mlx_get_data_addr(img->xpm,
				&(img->bits_per_pixel), &(img->line_len), &(img->endian));
}

void	load_sprites(t_game *game)
{
	load_img(game, &(game->wall), "./textures/wall.xpm");
	load_img(game, &(game->ground), "./textures/ground.xpm");
	load_img(game, &(game->collectible), "./textures/collectible.xpm");
	load_img(game, &(game->exit), "./textures/exit.xpm");
	load_img(game, &(game->player_left), "./textures/player_left.xpm");
	load_img(game, &(game->player_right), "./textures/player_right.xpm");
	load_img(game, &(game->player_up), "./textures/player_up.xpm");
	load_img(game, &(game->player_down), "./textures/player_down.xpm");
}

void	free_sprites(t_game *game)
{
	if (game->wall.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->wall.xpm);
	if (game->ground.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->ground.xpm);
	if (game->collectible.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->collectible.xpm);
	if (game->exit.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->exit.xpm);
	if (game->player_left.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->player_left.xpm);
	if (game->player_right.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->player_right.xpm);
	if (game->player_up.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->player_up.xpm);
	if (game->player_down.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->player_down.xpm);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

unsigned int	pixel_color(int x, int y, t_img *img)
{
	return (*(unsigned int *)(img->data + \
	(y * img->line_len + x * (img->bits_per_pixel / 8))));
}
