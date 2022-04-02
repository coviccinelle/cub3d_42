/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:26:15 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 11:37:19 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char c, int index, int size, t_game *game)
{
	if ((index == 0) || (index == size))
	{
		if (c != '1')
			error("Error\nMap is not surrounded by wallsi I\n", game);
	}
}

void	check_walls_h(char c, int index, int size, t_game *game)
{
	if ((index == 0) || (index == size))
	{
		if (c != '1')
			error("Error\nMap is not surrounded by walls J\n", game);
	}
}

void	check_keys(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (!(find_me(c, "P01EC\n")))
		error("Error\nInput wrong characters! Please check again!\n", game);
	if (c == 'C')
		game->nb_c += 1;
	if (c == 'E')
		game->nb_e += 1;
	if (c == 'P')
		game->nb_p += 1;
}

void	check_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_height)
	{
		if ((ft_strlen(game->map[i]) - 1) != game->map_width)
			error("Error\nMap is not rectangle\n", game);
		j = 0;
		while (game->map[i][j + 1])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			check_keys(game, i, j);
			check_walls(game->map[i][j], i, game->map_height, game);
			check_walls_h(game->map[i][j], j, game->map_width, game);
			j++;
		}
		i++;
	}
	if (game->nb_c < 1 || game->nb_e < 1 || game->nb_p != 1)
		error("Error\nMap error: wrong number of P, C or E\n", game);
}
