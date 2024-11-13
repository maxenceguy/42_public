/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:16:35 by mguy              #+#    #+#             */
/*   Updated: 2024/10/13 15:50:15 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "fcntl.h"
# include "../minilibx-linux/mlx.h"

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000

# define KEY_ESC 65307
# define KEY_W 119 
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define PLAYER_RADIUS 3
# define PI 3.14159265359

# define ROTATE_SPEED 30
# define MOVE_SPEED 0.1

typedef struct s_cub3d	t_cub3d;

typedef struct s_draw_texture_line
{
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;
	float	step;
	float	tex_pos;
	float	wall_start;
	float	wall_end;
	float	wall_height;
	float	textur_x_offset;
}	t_draw_texture_line;

typedef struct s_draw_line
{
	int		dx;
	int		dy;
	int		step;
	int		i;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	float	s_x;
	float	s_y;
	float	end_x;
	float	end_y;
}	t_draw_line;

typedef struct s_render3d
{
	float	field_of_view;
	float	half_fov;
	float	delta_angle;
	float	ray_angle;
	float	hit_x;
	float	hit_y;
	int		side;
	float	ray_distance;
	float	corrected_distance;
	float	wall_height;
	float	wall_start;
	float	wall_end;
	float	textur_x_offset;
	float	textur_y_offset;
}	t_render3d;

typedef struct s_texture
{
	void	*img;
	char	*pixels_ptr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_textures
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}	t_textures;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;
	float	dir_x;
	float	dir_y;
	float	angle;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

// Raycasting structure
typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	ray_dir_x;
	float	ray_dir_y;
}	t_ray;

typedef struct s_simulation
{
	t_img		*img;
	t_player	*player;
	t_textures	*textures;
	t_keys		*keys;
	void		*mlx_ptr;
	void		*win_ptr;
	int			tile_size;
	float		east;
	float		west;
	float		nord;
	float		south;
}	t_simulation;

typedef struct s_parsing
{
	t_cub3d	*cub3d;
	int		tmp_struct;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		after;
	char	**map;
	char	**file;
}	t_parsing;

typedef struct s_cub3d
{
	t_parsing		*parsing;
	t_simulation	*simulation;
}				t_cub3d;

void		free_all(t_cub3d *cube);
void		free_map_and_file(t_parsing *p);
void		free_parsing(t_parsing *p);

// ================== Parsing functions ==================
int			parse(t_cub3d *cube, int ac, char **av);
char		*get_next_line(int fd);
int			find_indent(char *file, char *to_find);
char		*get_next_part(char *file, int i);
int			get_map(t_parsing *p);
int			get_file(t_parsing *p, char **av);
int			*get_rgb(char *str);
char		*get_textures(t_parsing *p, char *cardinal_point);
int			check_validity(t_parsing *p);
int			find_map_start(char **file);

// ================== Simulation functions ==================
int			close_window(t_cub3d *cube3d);

// render
void		my_pixel_put(int x, int y, t_img *img, int color);
void		draw_map(t_simulation *sim, t_parsing *parsing);
void		draw_map_hook(t_simulation *sim, t_parsing *parsing, int tile_size);

//move
void		redraw(t_cub3d *cube3d);
void		move_forward(t_cub3d *cube3d);
void		move_backward(t_cub3d *cube3d);
void		move_left(t_cub3d *cube3d);
void		move_right(t_cub3d *cube3d);
int			key_press(int keycode, t_cub3d *cube3d);
int			key_release(int keycode, t_cub3d *cube3d);
int			handle_player_movement(t_cub3d *cube3d);
void		move_forward_backward(t_cub3d *cube3d, int *moved);
void		move_left_right(t_cub3d *cube3d, int *moved);
void		rotate_player(t_cub3d *cube3d, int *moved);
// init 
t_cub3d		*init_cub3d(int ac, char **av);
int			init_window_and_image(t_cub3d *cube3d);

// vector
void		draw_line(t_simulation *sim, t_draw_line *dl, int color);
void		draw_direction_vector(t_simulation *sim, t_player *player);
void		draw_direction_look(t_parsing *pars, t_simulation *sim,
				t_player *player);

// init textures
t_texture	*load_texture(void *mlx_ptr, char *file_path);
void		load_all_textures(t_parsing *p, t_simulation *sim);
int			get_texture_pixel_color(t_texture *texture, int x, int y);
t_texture	*select_texture(t_simulation *sim, int side);

// utils
int			pimped_cast(float num);
int			calculate_tile_size(int window_width, int window_height,
				int map_width, int map_height);

// ray cast
float		cast_ray_and_return_distance(t_parsing *parsing, t_player *player,
				t_render3d *rd);

// render_3d
void		render_3d_projection(t_parsing *pars, t_simulation *sim,
				t_player *player);

void		my_pixel_put_rgb(int x, int y, t_img *img, int color[3]);
void		my_pixel_put(int x, int y, t_img *img, int color);

// draw
void		draw_texture_line(t_simulation *sim, int x, t_texture *texture,
				t_draw_texture_line *dt);
void		draw_player(t_simulation *sim, float x, float y, float tile_size);
void		draw_tile(t_simulation *sim, int x, int y, int color);

#endif
