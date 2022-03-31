/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:43 by mloubet           #+#    #+#             */
/*   Updated: 2022/03/31 11:24:53 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangular(char **line, int ymax, int xmax)
{
	int	m;
	int	first_line_len;

	m = 1;
	first_line_len = xmax;
	while (line[m] && (m < ymax))
	{
		if ((int)ft_strlen(line[m]) != first_line_len)
			return (0);
		m++;
	}
	return (1);
}

// The map must be composed of only 6 possible characters:
// 0 for an empty space,
// 1 for a wall
// and N,S,E or W for the player’s start position and spawning orientation.
// north - south - east - west
// 2 for sprite (bonus)
int	right_chars(char **map, int e, int c1, int p)
{
	int	l;
	int	c;

	l = -1;
	while (map[++l])
	{
		c = -1;
		while (map[l][++c])
		{
			if (!find_me(map[l][c], "01NSEW"))
				return (0);
			// if (map[l][c] == 'E')
			// 	e++;
			(void)e;
			(void)c1;
			// else if (map[l][c] == 'C')
			// 	c1++;
			if (find_me(map[l][c], "NEWS"))
			 	p++;
		}
	}
	if (p != 1)
		return (0);
	return (1);
}

// check if map is surrounded by only walls = 1
// check around every 0 and player NEWS
//  if (map[x][y] == 0 || map[x][y] == "NEWS") -> if x
int	walls(char **map, int ymax, int xmax)
{
	int	y;
	int	x;

	y = -1;
	if ((ymax <= 2) || (xmax <= 2))
		return (0);
	while (map[++y] && (y < ymax))
	{
		x = -1;
		while (map[y][++x] && (x < xmax))
		{
			if ((map[0][x]) != '1')
				return (0);
			if ((map[ymax - 1][x]) != '1')
				return (0);
			if ((map[y][0]) != '1')
				return (0);
			if (map[y][xmax - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	right_map(char **map, int ymax, int xmax)
{
	if (!is_rectangular(map, ymax, xmax))
	{
		ft_putstr_fd("unvalid map, not rectangular\n", 2);
		return (0);
	}
	if (!right_chars(map, 0, 0, 0))
	{
		ft_putstr_fd("need 1 P, at least 1C and 1 E\n", 2);
		return (0);
	}
	if (!walls(map, ymax, xmax))
	{
		ft_putstr_fd("unvalid map, walls need to be closed\n", 2);
		return (0);
	}
	return (1);
}
