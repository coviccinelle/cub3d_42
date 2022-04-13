/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_bckr_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:48:46 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/13 15:04:35 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ❕❗❕❗❕❗❕❗❕❗
// function to stock color of the ceilling and the floor
void	stock_fc(t_game *game, int i, char *line)
{
	int	red;
	int	green;
	int	blue;

	red = atoi_i_pars(line, &i, game);
	green = atoi_i_pars(line, &i, game);
	blue = atoi_i_pars(line, &i, game);
	if (game->o != (ft_strlen(line) -1))
	{
		free(line);
		ft_puterror_exit("Right format: [R, G, B] without any char afterwards", \
		game);
	}
	if (red > 255 || red < 0 || green < 0 || green > 255 \
	|| blue < 0 || blue > 255)
	{
		free(line);
		ft_puterror_exit("RGB value invalid", game);
	}
	if (line[0] == 'F')
		game->draw.floor = create_trgb(0, red, green, blue);
	else
		game->draw.ceiling = create_trgb(0, red, green, blue);
}

void	stock_rfc(t_game *game, char *line)
{
	int		i;

	i = 1;
	stock_fc(game, i, line);
}

// check : NO SO EA ES long condition + sprire?!!!
void	stock_path(t_game *game, char *line)
{
	int	i;

	i = 3;
	while (line[i] == ' ')
		i++;
	if (line[0] == 'N' && line[1] == 'O')
		game->img[0].path = ft_strdup(&line[i]);
	else if (line[0] == 'S' && line[1] == 'O')
		game->img[1].path = ft_strdup(&line[i]);
	else if (line[0] == 'W' && line[1] == 'E')
		game->img[2].path = ft_strdup(&line[i]);
	else if (line[0] == 'E' && line[1] == 'A')
		game->img[3].path = ft_strdup(&line[i]);
}

// => 2nd function to store map header
//	- store_info : FC : Ceilling + Floor---    			
//					R -> game->win_width/height = atoi(&line[i])
//					F -> game->draw.floor = store_color(0, red, green, blue)
// 					NOEAWESO : -> store path 
void	stock_bckr_info(t_game *game, int fd, char *line)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line_2(fd);
		if (i == 0 && line == NULL)
		{
			printf("Map incomplete\n");
			exit (0);
		}
		if (line && find_me(line[0], "FC") && line[1] == ' ')
		{
			stock_rfc(game, line);
			i++;
		}	
		else if (is_texture(line, game))
		{
			stock_path(game, line);
			i++;
		}	
		else if (!line || i == 6)
			break ;
		free(line);
	}
}
