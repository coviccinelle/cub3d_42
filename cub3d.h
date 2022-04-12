/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:56:36 by thi-phng          #+#    #+#             */
/*   Updated: 2022/04/12 11:20:15 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER_SIZE 4095

# define MOVING_SPEED 0.12
# define ROTATION_SPEED 0.05

# define KEY_FORWARD 119
# define KEY_BACKWARD 115
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_TURN_LEFT 65363
# define KEY_TURN_RIGHT 65361
# define KEY_ESCAPE 65307

typedef struct s_img {
	char	*path;
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		width;
	int		height;
}				t_img;

typedef struct s_camera {
	double			plane_x;
	double			plane_y;
	double			pos_plane;
}				t_camera;

typedef struct s_ray {
	int				hit;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	double			dir_x;
	double			dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				side;
}				t_ray;

typedef struct s_player {
	double			pos_x;
	double			pos_y;
	char			start_dir;
	double			dir_x;
	double			dir_y;
	int				look_right;
	int				look_left;
	int				move_backward;
	int				move_forward;
	int				move_right;
	int				move_left;
}				t_player;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_draw
{
	int				floor;
	int				ceiling;
	int				line_start;
	int				line_end;
	int				line_size;
	int				x_texture;
	int				y_texture;

}				t_draw;

typedef struct s_game
{
	int				over;
	int				win_width;
	int				win_height;
	char			*map[1024];
	int				map_width;
	int				map_height;
	t_mlx			mlx;
	t_img			img[4];
	t_ray			ray;
	t_player		player;
	t_camera		camera;
	t_draw			draw;
	unsigned int	nb_p;
	double			dist_wall;
	double			wall_hit;
}				t_game;

//utils
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_puterror(char *str);
char			*ft_strdup(char *str);
void			ft_putchar(char c);
//malloc et free
void			init_struct(t_game *game);
int				exit_free(t_game *game);
void			free_textures(t_game *game);
void			free_map(t_game *game);
//parsing
int				parsing(int ac, char **av, t_game *game);
void			del(char **str);
int				find_me(char c, char *str);
int				atoi_i_pars(char *str, int *i, t_game *game);
char			*ft_strchr_2(const char *str, int c);
int				is_texture(char *str, t_game *game);

int				check_map_file_name(int ac, char **av, int fd);
void			stock_bckr_info(t_game *game, int fd, char *line);
void			stock_map(t_game *game, int fd);
void			check_map_body(t_game *game);

//gnl
int				ft_find(char c, const char *str);
void			*ft_memcpy(char *dst, char *src, int n);
char			*ft_strjoin_2(char *s1, char *s2);
char			*ft_del(char *str);
char			*ft_substr(char *s, int start, int len);
char			*get_next_line_2(int fd);

// exec
void			init_player(t_game *game);
int				ft_key_hook(int keycode, t_game *game);
int				ft_key_unhook(int keycode, t_game *game);
void			load_textures(t_game *game);
void			player_moves(t_game *game);
void			print_background(t_game *game);
unsigned int	create_trgb(int t, int r, int g, int b);
void			draw_color(int start_y, int end_y, unsigned int color, \
				t_game *game);
void			draw_walls(t_game *game, int x);
void			raycasting_initialize(t_game *game, int x);
void			raycasting_initialize2(t_game *game);
void			check_when_ray_hits_wall(t_game *game);
void			draw_calculations(t_game *game);

void			print_info(t_game *game);
void			ft_puterror_exit(char *str, t_game *game);
void			ft_putstr_fd(char *s, int fd);
void			ft_puterror_exit(char *str, t_game *game);
#endif
