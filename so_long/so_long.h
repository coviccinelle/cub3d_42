/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:57:17 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/12 11:35:25 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define BACKGR "./visual/backgr.xpm"
# define WALL "./visual/wall.xpm"
# define EXIT "./visual/exit.xpm"
# define COLL "./visual/coll.xpm"
# define PLAYER "./visual/player.xpm"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42000
# endif

enum	e_enum
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
};

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		nb_c;
	int		nb_e;
	int		nb_p;
	void	*img_backgr;
	void	*img_wall;
	void	*img_player;
	void	*img_coll;
	void	*img_exit;
	int		img_width;
	int		img_height;
	int		moves;
}				t_game;

// Utils //

int		ft_strlen(const char *str);
int		find_me(char c, const char *str);
char	*ft_strchr(const char *str, int c);

// GNL //
//
// done old ver //
int		ft_find(char c, const char *str);
void	*ft_memcpy(char *dst, char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_del(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_init_gnl(int fd, char *line, char *buf, int *ret);
char	*ft_next_line(char *line, char *buf, int nl_index);
char	*add_buf_to_line(char *line, char *buf);
int		ft_read(int fd, char *buf, char *line);
char	*get_next_line(int fd);

// -------------------- Key_events_utils -----------//
void	is_collected(char next_p, t_game *game);
void	mouvement(char next_p, int keypressed, t_game *game);
int		is_exit(char next_p, t_game *game);
char	set_next_p(int keypressed, t_game *game);

// Exit_Erro //

void	del(char **str);
void	del_map(char ***map);
void	ft_exit(t_game *game, int exit_type);
void	error(char *str, t_game *game);

// read_map //

void	get_map_size(char *map_file, t_game *game);
char	**fill_map(int fd, int height);
int		check_map_name(char *str);
void	read_map(char *map_file, t_game *game);

// ------------- CHECK_MAP-----------------//
void	check_walls(char c, int index, int size, t_game *game);
void	check_walls_h(char c, int index, int size, t_game *game);
void	check_keys(t_game *game, int i, int j);
void	check_map(t_game *game);

// ---------------init game ------------------//
void	init_struct(t_game *game);
void	file_to_image(t_game *game);
void	init_game(t_game *game);

//------------- display_game ---------------//
void	put_image(int x, int y, t_game *game);
int		images_to_window(t_game *game);
int		key_events(int keypressed, t_game *game);
int		close_x_exit(t_game *game);
void	display_game(t_game game);

//--------------- utils --------------------//

char	*get_next_line(int fd);
int		ft_read(int fd, char *buf, char *line);
char	*add_buf_to_line(char *line, char *buf);
char	*ft_next_line(char *line, char *buf, int nl_index);
char	*ft_init_gnl(int fd, char *line, char *buf, int *ret);
void	*ft_memcpy(char *dst, char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_del(char *str);
char	*ft_substr(char *s, int start, int len);
int		find_me(char c, const char *str);
char	*ft_strchr(const char *str, int c);

#endif
