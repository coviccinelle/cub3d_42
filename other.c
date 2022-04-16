/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:10:27 by mloubet           #+#    #+#             */
/*   Updated: 2022/04/16 15:35:47 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exception(t_game *game, char *str, int *i)
{
	int	j;
	int	cnt;

	j = -1;
	cnt = 0;
	if (!str || !find_me(str[*i], "0123456789 ,+-"))
	{
		free(str);
		ft_puterror_exit("Wrong char in map header", game);
	}
	while (str[++j])
	{
		if (str[j] == ',' )
			cnt++;
	}
	if (cnt != 2)
	{
		free(str);
		ft_puterror_exit("parsing error trop de virgules", game);
	}
}

int	atoi_bis(int *i, int nbr, char *str, t_game *game)
{
	int	nb_chiffres;

	nb_chiffres = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr * 10 + str[*i] - '0';
		(*i)++;
		nb_chiffres++;
	}
	if (nb_chiffres != 3)
	{	
		free(str);
		ft_puterror_exit("RGB value must be 3 numbers per R G B top", game);
	}
	return (nbr);
}

int	atoi_i_pars(char *str, int *i, t_game *game)
{
	int		sign;
	long	nbr;
	int		mark;

	nbr = 0;
	sign = 1;
	exception(game, str, i);
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || \
	str[*i] == ' ' || str[*i] == ','))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		free(str);
		ft_puterror_exit("RGB value must be without +- or else", game);
	}
	mark = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		nbr = atoi_bis(i, nbr, str, game);
	if (mark == *i)
		return (-1);
	game->o = (*i);
	return (nbr * sign);
}

int	is_0(char c)
{
	if (!find_me(c, "10NEWS"))
		return (0);
	return (1);
}
