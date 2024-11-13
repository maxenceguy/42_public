/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:44:37 by mxc               #+#    #+#             */
/*   Updated: 2024/03/22 16:05:40 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TILE_SIZE 48
# define FRAME_DELAY 16666666
# define NANOSECONDS_PER_SECOND 1000000000
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define SCROLL_STEP 48

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*character;
	void	*chest_close;
	void	*chest_open;
	void	*door_open;
	void	*door_close;
	void	*img;
	char	**map;
	int		player_x;
	int		player_y;
	int		map_height;
	int		map_width;
	int		total_check;
	int		check;
	int		open;
	int		char_offset_x;
	int		char_offset_y;
	int		exit_requested;
	int		nb_mouv;
}				t_data;

// main.c
int		loop_hook(t_data *data);
int		main(int ac, char **av);

// get_map.c
char	**get_file(char *filename);
int		count_tab_size(t_data *data);
int		count_check(t_data *data);
int		get_map(t_data *data, int ac, char **av);
void	free_tab(t_data *data);

// draw_map.c
int		open_exit(t_data *d);
int		put_sprite(t_data *d, char tile, int tx, int ty);
int		find_sprite(t_data *data, int char_x, int char_y);
void	draw_map(t_data *data);

// events.c
int		events(t_data *data);
int		key_press(int keycode, t_data *data);
int		can_move(t_data *data, int new_x, int new_y);
int		close_win(t_data *data);

// init.c
void	get_env(t_data *data);
void	set_initial_offsets(t_data *data);

// check_map.c
void	rect_map(t_data *data, char **m);
int		comp_components(t_data *data, char c, int *l);
int		components(t_data *data, char **map);
void	check_map(t_data *data);

// resolved_map.c
int		find_p(t_data *d, int *x, int *y);
int		path(t_data *d, int **v, int x, int y);
int		resolved_map(t_data *d);

// end.c
int		check_ext(char *filename);
char	*exit_error(t_data *data, char *mess);
void	destroy_all(t_data *data);

#endif
