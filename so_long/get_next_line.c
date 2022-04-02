/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:07:23 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/10 11:50:28 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_init_gnl(int fd, char *line, char *buf, int *ret)
{
	if ((BUFFER_SIZE <= 0) || (fd < 0))
		return (NULL);
	*ret = 1;
	line = ft_substr(buf, 0, ft_find('\0', buf));
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_next_line(char *line, char *buf, int nl_index)
{
	char	*free_var;

	ft_memcpy(buf, line + nl_index + 1, (ft_find('\0', line) - (nl_index + 1)));
	buf[ft_find('\0', line) - (nl_index + 1)] = '\0';
	free_var = line;
	line = ft_substr(line, 0, nl_index + 1);
	ft_del(free_var);
	if (!line)
		return (NULL);
	return (line);
}

char	*add_buf_to_line(char *line, char *buf)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, buf);
	ft_del(tmp);
	if (!line)
		return (NULL);
	return (line);
}

int	ft_read(int fd, char *buf, char *line)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (ret == -1)
	{
		ft_del(line);
		return (-1);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	char			*line;
	int				ret;
	int				nl_index;

	line = NULL;
	line = ft_init_gnl(fd, line, buf, &ret);
	if (!line)
		return (NULL);
	while (ret)
	{
		nl_index = ft_find('\n', line);
		if ((nl_index) || line[0] == '\n')
			return (ft_next_line(line, buf, nl_index));
		ret = ft_read(fd, buf, line);
		if (!ret)
			break ;
		line = add_buf_to_line(line, buf);
		if (!line || ret == -1)
			return (NULL);
	}
	if (line[0])
		return (line);
	return (ft_del(line));
}
