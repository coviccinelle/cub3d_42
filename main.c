/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:12:47 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/02 21:12:54 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
