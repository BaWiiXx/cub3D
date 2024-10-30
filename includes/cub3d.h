/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:16:22 by egomez            #+#    #+#             */
/*   Updated: 2024/10/30 13:51:44 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../src/parsing/get_next_line/get_next_line.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define S_W 1080
# define S_H 720
# define T_W 64
# define T_H 64
# define SPEED 0.06
# define ROTATE_SPEED 0.05
# define WALL_DISTANCE 5

typedef struct s_ceilfloor
{
	uint32_t		ceil_color;
	uint32_t		floor_color;
}					t_ceilfloor;

typedef struct s_text
{
	mlx_image_t		*texture[4];
	mlx_texture_t	*path[4];
	int				count_so;
	int				count_no;
	int				count_we;
	int				count_ea;
	int				count_c;
	int				count_f;
	int				direction;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	uint32_t		color;
}					t_text;

typedef struct s_player
{
	double			x;
	double			y;
	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			old_dirx;
	double			old_planex;
	char			orientation;
}					t_player;

typedef struct s_map
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				line;
	int				line_cpy_tab;
	int				dir;
	int				start_map;
	char			**all_map;
	char			**map;
}					t_map;

typedef struct s_ray
{
	double			ray_x;
	double			ray_y;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				draw_start;
	int				draw_end;
	double			wall_x;
}					t_ray;

typedef struct s_game
{
	int				x;
	int				y;
	int				fd;
	int				count_flood;
	t_player		player;
	t_map			map;
	t_ray			ray;
	t_text			texture;
	t_ceilfloor		ceilfloor;
}					t_game;

void				exit_error(char *str);
void				size_map(t_game *data);
void				check_texture(char **map, t_game *data);
void				get_pos_player(t_game *pos);
void				check_for_texture(char **map, t_game *data);
void				check_zero(t_game *game, char **map_cpy);
void				parse_map(t_game *data);
void				init_all_of_value(t_game *data);
size_t				ft_strlen(const char *s);
void				free_tab(char **tab);
char				**get_map(t_game *data);
void				check_cub_argv(char *argv);
void				open_fd(t_game *data, char **argv);
int					ft_strcmp(const char *s1, const char *s2);
void				set_color(t_game *data, char *line, int *count);
char				**cpy_tab(t_game *data);
void				is_empty_line(char *line, t_game *data);
void				validate_line(char *line, t_game *data);
void				exit_free_all(char *str, t_game *data);
int					check_open_texture(char *str, t_game *data, char **split);

void				init_mlx(t_game *game);
void				player_orientation(t_game *game);
void				init_text(t_game *game);

void				start_game(t_game *game);

void				move(t_game *game);
void				rotate2(t_game *game);
void				update(t_game *game);
uint32_t			get_color_rgba(int r, int g, int b, int a);

void				raycasting(t_game *game);
void				raycasting2(t_game *game);
void				raycasting3(t_game *game);
void				raycasting4(t_game *game);
void				raycasting5(t_game *game);

void				draw_ceiling_floor(t_game *game, int draw_start,
						int draw_end, uint32_t color);
void				draw_textures(t_game *game);

void				free_all(t_game *game);
#endif
