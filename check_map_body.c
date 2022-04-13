/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:00:03 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/13 14:29:44 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ❕❗❕❗❕❗❕❗❕❗
//to check if there's other char than "01 NEWS"
void	check_keys(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (!(find_me(c, "01 NEWS\n")))
	{
		ft_puterror_exit("Input wrong characters! Please check again!", game);
	}
}

void	check_outside_wall(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_puterror_exit("Map is not covered by walls", game);
		i++;
	}
}

int	is_err(char c)
{
	if (!find_me(c, "10"))
		return (1);
	return (0);
}

int	is_0(char c)
{
	if (!find_me(c, "10NEWS"))
		return (0);
	return (1);
}

// a function to check aroud every 0 -> every space '0' need to be 
// covered with another valid
// character as 01NEWS and not an espace or anthing else

// around 0 is not an espace -> it can be a wall 1, 0 espace or player NEWS
void	check_around(char c, int i, int j, t_game *game)
{
	char	**m;

	m = game->map;
	if (i == 0 || i == game->map_height - 1)
		check_outside_wall(game->map[i], game);
	else if (c == '0')
	{
		if (!is_0(m[i + 1][j]) || !is_0(m[i - 1][j]) || \
		(!is_0(m[i][j + 1])) || (!is_0(m[i][j - 1])) || \
		(!is_0(m[i + 1][j - 1])) || !is_0(m[i + 1][j + 1]) || \
		!is_0(m[i - 1][j + 1]) || !is_0(m[i - 1][j - 1]))
		{
			ft_puterror_exit("At least one of the wall is missing", game);
		}
	}
	if (find_me(c, "NEWS"))
	{
		if (is_err(m[i + 1][j]) || is_err(m[i - 1][j]) || \
		is_err(m[i][j + 1]) || is_err(m[i][j - 1]) || \
		is_err(m[i + 1][j - 1]) || is_err(m[i + 1][j + 1]) || \
		is_err(m[i - 1][j + 1]) || is_err(m[i - 1][j - 1]))
			ft_puterror_exit("Map invalid", game);
	}
}
	// a player needs to be surrounded by only wall 1 or space 0
	// around player is not an espace and not player -> only 0 or 1

int	is_blank(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[0])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

//	4th function to check_map_body => careful with spaces and empty lines
void	check_map_body(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map_height)
	{
		j = 0;
		if (game->map[i] && is_blank(game->map[i]) && (i != 0))
			ft_puterror_exit("Empty line invalid (middle/beginning)", game);
		while (game->map[i][j])
		{
			if (find_me(game->map[i][j], "NEWS"))
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				game->player.start_dir = game->map[i][j];
				game->nb_p += 1;
			}
			check_keys(game, i, j);
			check_around(game->map[i][j], i, j, game);
			j++;
		}
	}
	if (game->nb_p != 1)
		ft_puterror_exit("Map error: wrong number of Player", game);
}
