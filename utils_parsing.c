/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:16:13 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/16 15:36:13 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// UTILS //
int	find_me(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	del(char **str)
{
	if (str && (*str))
	{
		free (*str);
		*str = NULL;
	}
}

char	*ft_strchr_2(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != c)
	{
		if (s[i] != '\0')
			return (0);
		i++;
	}
	return (&s[i]);
}

int	is_texture(char *str, t_game *game)
{
	if (!str)
		ft_puterror_exit("Invalid map header", game);
	if ((((str[0] == 'N' && str[1] == 'O') || \
		(str[0] == 'S' && str[1] == 'O') || \
		(str[0] == 'W' && str[1] == 'E') || \
		(str[0] == 'E' && str[1] == 'A')) \
		&& str[2] == ' '))
		return (1);
	return (0);
}

int	is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[0])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
