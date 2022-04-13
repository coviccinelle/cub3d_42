/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:33:04 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/13 11:33:02 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ------------------ PARSING -----------
int	parsing(int ac, char **av, t_game *game)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
	{
		printf("Map is a directory\n");
		close(fd);
		return (0);
	}
	fd = 0;
	fd = open(av[1], O_RDONLY);
	if (check_map_file_name(ac, av, fd))
		return (0);
	stock_bckr_info(game, fd, line);
	stock_map(game, fd);
	check_map_body(game);
	close(fd);
	return (1);
}
