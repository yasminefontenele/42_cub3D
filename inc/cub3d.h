/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliskam <eliskam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:21:36 by emencova          #+#    #+#             */
/*   Updated: 2024/11/04 12:11:32 by eliskam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define MEMORY_ERROR "Memory allocation failed"
# define INVALID_AC "Wrong number of arguments."
# define MAP_NAME "Invalid map name."
# define MAP_NOT_OPEN "Failed to open map file"
# define MAP_INVALID "Map validation failed"
# define EMPTY_MAP "Empty map file."
# define WRONG_EXT "Wrong file extension!! must be .cub"
# define MULT_PLAYER "Multiple player positions found in map"
# define NO_PLAYER "No player position found in map"
# define INVALID_CHAR "Invalid character in map"
# define COLOR_RANGE "Color values out of range."
# define COLOR_FORMAT "Color format incorrect."
# define WRONG_TEX "Wrong texture path."

# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"
# define RESET "\033[0m"

# define TILE_SIZE	64
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

# define WIDTH		800
# define HEIGHT		800

# define MOVE_SPEED		0.1
# define ROTATE_SPEED	0.1
# define COLLISION		0.1

typedef struct s_ray
{
	double		direc_x;
	double		wallx;
	double		direc_y;
	int			grid_x;
	int			grid_y;
	double		dist_to_sidex;
	double		dist_to_sidey;
	double		dist_deltax;
	double		dist_deltay;
	int			step_directx;
	int			step_directy;
	int			wall_side;
	double		wall_dist;
	int			start_draw;
	int			end_draw;
}				t_ray;

typedef struct s_color
{
	int	rgb;
}			t_color;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	char	**layout;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
}		t_map;

typedef struct s_player
{
	double	pos_y;
	double	pos_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mov_sp;
	double	rot_sp;
}			t_player;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		width;
	int		height;
	void	*north_img;
	void	*south_img;
	void	*west_img;
	void	*east_img;
}			t_texture;

typedef struct s_game
{
	t_player	player;
	int			floor_color;
	int			ceiling_color;
	t_texture	texture;
	t_color		color;
	t_map		map;
	t_data		data;
}			t_game;

void	load_map(const char *filename, t_game *game,char **av);
void	parse_map(char **file_lines, t_map *map);
void	parse_player(t_map *map, t_game *game);
char	**read_file_cub(const char *filename);
int		validate_map(char **map_tab, int height);
int		count_lines(const char *filename);
void	free_file_lines(char **lines);
void	free_split(char **split);
int		parse_color(const char *line, t_color *color);
void	move_y(t_game *game, char direction);
void	move_x(t_game *game, char direction);
void	move_player(t_game *game, char direction);
void	rotate_player(t_game *game, float angle);
int		is_valid_map_char(char c);
int		check_row_border(char **map_tab, int row, int start);
int		close_window(t_game *game);
int		handle_key(int keycode, t_game *game);
void	game_init(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	raycasting(t_game *game);
void	init_player(t_game *game, int x, int y, char direction);
int		validate_input(t_map *map, char **av);
char	*get_next_line(int fd);
void	events_init(t_game *game);
void	free_map(t_map *map);
void	load_textures(t_game *game);
int		get_cell_color(char cell, t_game *game);
int		render_frame(t_game *game);
void	render_player(t_data *data, t_game *game);
void	clear_screen(t_data *data);
void	free_texture(t_game *game);
void	draw_scene(t_game *game, int x, t_ray *ray);
void	initialize_dda(t_game *game, t_ray *ray);
void	calculate_ray_direction(t_game *game, int x, t_ray *ray);
double	calculate_perpendicular_distance(t_game *game, t_ray *ray);
int		perform_dda(t_game *game, t_ray *ray);
void	draw_vertical_line(t_game *game, int x, t_ray *ray, void *texture);
void	draw_floor_and_ceiling(t_game *game, int x, t_ray *ray);
void	destroy_image(void *mlx, void **img);
void	free_map(t_map *map);
int		close_window(t_game *game);
void	calculate_delta_distance(t_ray *ray);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray);
void	calculate_draw_positions(t_ray *ray);
int		initialize_game_data(t_game *game);
int		my_isspace(int c);
char	*trim_whitespace(char *str);
void	allocate_map_row(char **row, int width);
void	allocate_empty_row(char *map_row, int width);
void	allocate_map_layout(t_map *map);
void	free_textures(t_game *game);
void	free_img(t_game *game);
int		validate_input(t_map *map, char **av);
#endif
