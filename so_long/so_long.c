/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:07:05 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 12:54:29 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_struct(&game);
	if (ac == 2)
	{
		read_map(av[1], &game);
		check_map(&game);
		init_game(&game);
		display_game(game);
	}
	error("Error\nWrong number of arguments\n", NULL);
	return (0);
}
