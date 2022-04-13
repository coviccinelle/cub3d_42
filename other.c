/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:10:27 by mloubet           #+#    #+#             */
/*   Updated: 2022/04/13 14:57:41 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exception(t_game *game, char *str, int *i)
{
	if (!str || !find_me(str[*i], "0123456789 ,+-"))
	{
		free(str);
		ft_puterror_exit("Wrong char in map header", game);
	}
}

int	atoi_i_pars(char *str, int *i, t_game *game)
{
	int		sign;
	long	nbr;
	int		mark;

	nbr = 0;
	sign = 1;
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || \
	str[*i] == ' ' || str[*i] == ','))
		(*i)++;
	exception(game, str, i);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	mark = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr * 10 + str[*i] - '0';
		(*i)++;
	}
	if (mark == *i)
		return (-1);
	game->o = (*i);
	return (nbr * sign);
}
