/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:59:00 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/16 14:40:07 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ❕❗❕❗❕❗❕❗❕❗
void	get_map_size(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line_2(fd);
	game->map_width = ft_strlen(line);
	i = 0;
	while (line)
	{
		if (game->map_width < (ft_strlen(line)))
			game->map_width = ft_strlen(line);
		if (line[0] == '\0')
			game->map[i] = (char *)ft_strdup("");
		game->map[i] = (char *)ft_strdup(line);
		i++;
		free(line);
		line = get_next_line_2(fd);
	}
	game->map[i] = NULL;
	del(&line);
	game->map_height = i;
	if (game->map_height == 1024)
		ft_puterror_exit("Map is too big\n", game);
}

// 	3rd function to store map + fill _map
void	stock_map(t_game *game, int fd)
{
	get_map_size(fd, game);
}
