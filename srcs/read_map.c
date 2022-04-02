/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:15:25 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/02 21:33:39 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_map_size(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error("Error\nOpen failed\n", NULL);
	line = get_next_line(fd);
	game->map_width = ft_strlen(line) - 1;
	i = 1;
	while (line)
	{
		i++;
		del(&line);
		line = get_next_line(fd);
	}
	del(&line);
	game->map_height = i - 1;
}

char	**fill_map(int fd, int height)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		error("Error\nMap malloc failed\n", NULL);
		return (NULL);
	}
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if ((ft_strchr(map[i], '\n')))
			*(ft_strchr(map[i], '\n')) = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	check_map_name(char *map_name)
{
	int		len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] == '.' && map_name[len - 3] == 'b'
		&& map_name[len - 2] == 'e' && map_name[len - 1] == 'r')
		return (EXIT_SUCCESS);
	else
		error("Error\nWrong file name extension\n", NULL);
	return (0);
}

void	read_map(char *map_file, t_game *game)
{
	int		fd;

	check_map_name(map_file);
	get_map_size(map_file, game);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error("Error\nOpen failed\n", NULL);
	game->map = fill_map(fd, game->map_height);
}
