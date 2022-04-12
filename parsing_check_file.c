/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:47:28 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 19:03:37 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ❕❗❕❗❕❗❕❗❕❗
// - 1st function ✅ => check map file + name 
int	check_map_file_name(int ac, char **av, int fd)
{
	int	len;

	len = ft_strlen(av[1]);
	if (ac != 2)
		return (ft_puterror("Wrong number of arguments"));
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'c' || \
	av[1][len - 2] != 'u' || av[1][len - 1] != 'b')
		return (ft_puterror("Map name errored (not .cub extension)"));
	if (fd < 0)
		return (ft_puterror("Operation file corrupted"));
	return (false);
}
