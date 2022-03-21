#include "cub3d.h"

void	init_values(t_game *game)
{
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->img.width = 0;
	game->img.height = 0;
	game->img.xpm = 0;
	game->ground.xpm = 0;
	game->wall.xpm = 0;
	game->collectible.xpm = 0;
	game->exit.xpm = 0;
	game->pacman_left.xpm = 0;
	game->pacman_right.xpm = 0;
	game->pacman_up.xpm = 0;
	game->pacman_down.xpm = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_values(&game);
	if (ac == 2)
	{
        read_map(av[1], &game);
		check_map(&game);
		init_game(&game);
		display_game(game);

        /*
		get_rightfile(av, &game);
        //get map info
        //
		if (right_map(game.map, game.win_height, game.win_width))
		{
			init_struct(&game, game.map, game.win_height, game.win_width);
			window_display(&game);
		}
		else
		{
			free_tab(&game.map);
			exit(0);
		}
        */
	}
	else
		ft_putstr_fd("Error, get a ber file \n", 2);
	return (0);
}