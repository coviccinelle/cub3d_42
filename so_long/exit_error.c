/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:52:51 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 11:40:15 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del(char **str)
{
	if (str && (*str))
	{
		free (*str);
		*str = NULL;
	}
}

void	del_map(char ***map)
{
	int	i;

	if (map && (*map))
	{
		i = 0;
		while ((*map)[i])
		{
			del(&(*map)[i]);
			i++;
		}
		del((char **)map);
	}
}

void	ft_exit(t_game *game, int exit_type)
{
	if (game)
	{
		if (game->map)
			del_map(&game->map);
		if (game->img_backgr)
			mlx_destroy_image(game->mlx_ptr, game->img_backgr);
		if (game->img_wall)
			mlx_destroy_image(game->mlx_ptr, game->img_wall);
		if (game->img_exit)
			mlx_destroy_image(game->mlx_ptr, game->img_exit);
		if (game->img_coll)
			mlx_destroy_image(game->mlx_ptr, game->img_coll);
		if (game->img_player)
			mlx_destroy_image(game->mlx_ptr, game->img_player);
		if (game->window)
			mlx_destroy_window(game->mlx_ptr, game->window);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
	}
	exit(exit_type);
}

void	error(char *str, t_game *game)
{
	printf("%s\n", str);
	ft_exit(game, -1);
}
