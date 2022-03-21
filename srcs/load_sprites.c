#include "cub3d.h"

void	load_img(t_game *game, t_img *img, char *path)
{
	img->xpm = mlx_xpm_file_to_image(game->mlx.ptr, path,
			&(img->width), &(img->height));
	if (!img->xpm)
	{
		printf("Error\nImage not found : %s\n", path);
		free_sprites(game);
		free_tab(&game->map);
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
		exit(0);
	}
	if (img->xpm)
		img->data = mlx_get_data_addr(img->xpm,
				&(img->bits_per_pixel), &(img->line_len), &(img->endian));
}

void	load_sprites(t_game *game)
{
	load_img(game, &(game->wall), "./textures/wall.xpm");
	load_img(game, &(game->ground), "./textures/ground.xpm");
	load_img(game, &(game->collectible), "./textures/collectible.xpm");
	load_img(game, &(game->exit), "./textures/exit.xpm");
	load_img(game, &(game->pacman_left), "./textures/pacman_left.xpm");
	load_img(game, &(game->pacman_right), "./textures/pacman_right.xpm");
	load_img(game, &(game->pacman_up), "./textures/pacman_up.xpm");
	load_img(game, &(game->pacman_down), "./textures/pacman_down.xpm");
}
