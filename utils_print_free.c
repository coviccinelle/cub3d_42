/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:24:59 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 11:34:48 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info_ok(t_game *game)
{
	printf("------------------------------\n");
	printf("Floor Color : %d\n", game->draw.floor);
	printf("Ceiling Color : %d\n", game->draw.ceiling);
	printf("------------------------------\n");
	printf("NO Texture Path : %s\n", game->img[0].path);
	printf("SO Texture Path : %s\n", game->img[1].path);
	printf("WE Texture Path : %s\n", game->img[2].path);
	printf("EA Texture Path : %s\n", game->img[3].path);
	printf("------------------------------\n");
	printf("X Position : %f\n", game->player.pos_x);
	printf("Y Position : %f\n", game->player.pos_y);
	printf("Starting Direction : %c\n", game->player.start_dir);
	printf("X Map Size : %d\n", game->map_width);
	printf("Y Map Size : %d\n", game->map_height);
}

void	print_info(t_game *game)
{
	int	i;

	i = 0;
	printf("------------------------------\n");
	if (game->draw.floor && game->draw.ceiling && game->img[0].path && \
	game->img[1].path && game->img[2].path && game->img[3].path && \
	game->player.pos_x && game->player.pos_y && game->player.start_dir && \
	game->map_width && game->map_height)
	{
		printf("\nYour Map is Correct\n");
		print_info_ok(game);
	}
	printf("---------------------------------\n");
	while (i < game->map_height)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("---------------------------------\n");
}
