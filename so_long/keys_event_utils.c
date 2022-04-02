/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:37:02 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 11:51:06 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collected(char next_p, t_game *game)
{
	if (next_p == 'C')
		game->nb_c -= 1;
}

void	mouvement(char next_p, int keypressed, t_game *game)
{
	if (keypressed == W)
		game->player_y -= 1;
	if (keypressed == S)
		game->player_y += 1;
	if (keypressed == A)
		game->player_x -= 1;
	if (keypressed == D)
		game->player_x += 1;
	is_collected(next_p, game);
}

int	is_exit(char next_p, t_game *game)
{
	if (next_p == 'E')
	{
		if (game->nb_c == 0)
			ft_exit(game, 1);
		else
			return (1);
	}
	return (0);
}

char	set_next_p(int keypressed, t_game *game)
{
	int		x;
	int		y;
	char	**map;
	char	next_p;

	x = game->player_x;
	y = game->player_y;
	map = game->map;
	next_p = '\0';
	if (keypressed == ESC)
		ft_exit(game, 1);
	if (keypressed == W)
		next_p = map[y - 1][x];
	if (keypressed == A)
		next_p = map[y][x - 1];
	if (keypressed == S)
		next_p = map[y + 1][x];
	if (keypressed == D)
		next_p = map[y][x + 1];
	return (next_p);
}
