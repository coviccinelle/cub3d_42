/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:13:17 by mloubet           #+#    #+#             */
/*   Updated: 2022/04/13 15:11:31 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->img[i].path)
		{
			free(game->img[i].path);
			if (game->img[i].img)
				mlx_destroy_image(game->mlx.ptr, game->img[i].img);
		}
	}
}

void	free_img(void *mlx, t_img *img)
{
	free(img->path);
	mlx_destroy_image(mlx, img->img);
}

void	tmp(t_game *game)
{
	free_map(game);
	if (game->img[NORTH].img)
		free_img(game->mlx.ptr, &game->img[NORTH]);
	if (game->img[SOUTH].img)
		free_img(game->mlx.ptr, &game->img[SOUTH]);
	if (game->img[WEST].img)
		free_img(game->mlx.ptr, &game->img[WEST]);
	if (game->img[EAST].img)
		free_img(game->mlx.ptr, &game->img[EAST]);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (game->mlx.win)
		mlx_destroy_image(game->mlx.ptr, game->mlx.img);
	if (game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}

int	exit_free(t_game *game)
{
	tmp(game);
	exit(0);
}

void	ft_puterror_exit(char *str, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit_free(game);
	free_map(game);
	free_textures(game);
	if (game->mlx.ptr && game->mlx.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.img);
	if (game->mlx.ptr && game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
	exit(0);
}
