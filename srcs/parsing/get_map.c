#include "cub3d.h"

void	del(char **str)
{
	if (str && (*str))
	{
		free (*str);
		*str = NULL;
	}
}

void	get_map_size(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		perror(map_file);
	line = get_next_line(fd);
	game->map_width = ft_strlen(line) - 1;
	i = 1;
	while (line)
	{
		i++;
		del(&line);
		line = get_next_line(fd);
	}
	del(&line);
	game->map_height = i - 1;
}

char	**fill_map(int fd, int height)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		error("Error\nMap malloc failed\n", NULL);
		return (NULL);
	}
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if ((ft_strchr(map[i], '\n')))
			*(ft_strchr(map[i], '\n')) = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

//file extension checking + check if directory or not
void	get_rightfile(char *map_name)
{
	int	fd;

	fd = open(map_name, O_WRONLY);
	if ((fd == -1)
		|| ((!ft_strcmp_end(map_name, ".cub"))))
    {
        close(fd);
        exit_error_fd("please get an actual .cub file\n");
    }
}

void	read_map(char *map_file, t_game *game)
{
	int		fd;

	get_rightfile(map_file);
	get_map_size(map_file, game);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		perror(map_file);
	game->map = fill_map(fd, game->map_height);
}
