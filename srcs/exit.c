#include "cub3d.h"

void	exit_game(t_game *game)
{
	free_sprites(game);
	mlx_destroy_image(game->mlx.ptr, game->img.xpm);
	mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.ptr);
	game->mlx.win = NULL;
	free(game->mlx.ptr);
	free_tab(&game->map);
	exit(1);
}

void	free_tab(char ***line)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		free((*line)[i]);
		i++;
	}
	free((*line)[i]);
	free(*line);
}

void	free_sprites(t_game *game)
{
	if (game->wall.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->wall.xpm);
	if (game->ground.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->ground.xpm);
	if (game->collectible.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->collectible.xpm);
	if (game->exit.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->exit.xpm);
	if (game->pacman_left.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->pacman_left.xpm);
	if (game->pacman_right.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->pacman_right.xpm);
	if (game->pacman_up.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->pacman_up.xpm);
	if (game->pacman_down.xpm && game->mlx.ptr)
		mlx_destroy_image(game->mlx.ptr, game->pacman_down.xpm);
}