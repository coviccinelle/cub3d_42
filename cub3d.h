
#ifndef CUB3D_H
# define CUB3D_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


/* MAC
# define ESC  53
# define UP_W 13
# define UP   126
# define DOWN_S 1
# define DOWN 125
# define LEFT_A 0
# define LEFT 123
# define RIGHT_D 2
# define RIGHT 124
*/

//Linux
# define ESC  65307
# define UP_W 119
# define UP   65362
# define DOWN_S 115
# define DOWN 65364
# define LEFT_A 97
# define LEFT 65361
# define RIGHT_D 100
# define RIGHT 65363

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct s_img
{
	void	*xpm;
	char	*data;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	int	orientation_x;
	int	orientation_y;
	int	prev_x;
	int	prev_y;
	int	curr_x;
	int	curr_y;
	int	collectibles;
	int	n_moves;
}				t_player;

typedef struct s_game
{
	t_mlx		mlx;
	t_img		img;
	t_img		ground;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_img		player_left;
	t_img		player_right;
	t_img		player_up;
	t_img		player_down;
    t_player	player;

	char	    **map;
	int		    map_width;
	int		    map_height;

	int		nb_e;
	int		nb_p;
	int		nb_xxxxxetc;
/*	char		**map;
	int			width;
	int			height;
	int			bpp;
	int			win_width;
	int			win_height;*/
	
}				t_game;



void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int     ft_strcmp(char *s, char *t);
int     ft_strcmp_end(char *s, char *t);

//exit game
void	exit_game(t_game *game);
void	free_tab(char ***line);
void	free_sprites(t_game *game);

//sprites
void	load_sprites(t_game *game);
void	load_img(t_game *game, t_img *img, char *path);

//player moves
int     handle_player_moves(int keysym, t_game *game);
int     move_player(int next_x, int next_y, t_game *game);
void	init_values(t_game *game);
char	*get_next_line(int fd);
int     ft_find(char c, const char *str);
void	read_map(char *map_file, t_game *game);

//get next line
char	*ft_init_gnl(int fd, char *line, char *buf, int *ret);
char	*ft_next_line(char *line, char *buf, int nl_index);
char	*add_buf_to_line(char *line, char *buf);
int		ft_read(int fd, char *buf, char *line);
char	*get_next_line(int fd);
//get right map
void	del(char **str);
void	get_map_size(char *map_file, t_game *game);
char	**fill_map(int fd, int height);
void	get_rightfile(char *map_name);
void	read_map(char *map_file, t_game *game);

void	view_tab(char **s);
char	*ft_strchr(const char *str, int c);
void	check_map(t_game *game);
#endif
