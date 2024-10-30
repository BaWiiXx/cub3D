/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:17 by egomez            #+#    #+#             */
/*   Updated: 2024/10/23 14:09:49 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycasting2(t_game *game)
{
	if (game->ray.ray_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.x - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1 - game->player.x)
			* game->ray.deltadist_x;
	}
	if (game->ray.ray_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.y - game->ray.map_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1 - game->player.y)
			* game->ray.deltadist_y;
	}
	raycasting3(game);
}

void	raycasting3(t_game *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0 && \
	game->ray.ray_x - game->ray.map_x < 1000 && \
	game->ray.ray_y - game->ray.map_y < 1000)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
	if (game->ray.side == 0)
		game->ray.perpwalldist = game->ray.sidedist_x - game->ray.deltadist_x;
	else
		game->ray.perpwalldist = game->ray.sidedist_y - game->ray.deltadist_y;
	raycasting4(game);
}

void	raycasting4(t_game *game)
{
	game->ray.lineheight = (int)(S_H / game->ray.perpwalldist);
	game->ray.draw_start = -game->ray.lineheight / 2 + S_H / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.lineheight / 2 + S_H / 2;
	if (game->ray.draw_end >= S_H)
		game->ray.draw_end = S_H;
	if (game->ray.side == 1)
		game->ray.wall_x = game->player.x + game->ray.perpwalldist
			* game->ray.ray_x;
	else
		game->ray.wall_x = game->player.y + game->ray.perpwalldist
			* game->ray.ray_y;
	game->ray.wall_x -= floor((game->ray.wall_x));
	game->texture.tex_x = (int)(game->ray.wall_x * (double)T_W);
	if (game->ray.side == 0 && game->ray.ray_x > 0)
		game->texture.tex_x = T_W - game->texture.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_y < 0)
		game->texture.tex_x = T_W - game->texture.tex_x - 1;
	game->texture.step = 1.0 * T_H / game->ray.lineheight;
	game->texture.tex_pos = (game->ray.draw_start - \
	S_H / 2 + game->ray.lineheight / 2) * game->texture.step;
	raycasting5(game);
}

void	raycasting5(t_game *game)
{
	game->y = game->ray.draw_start;
	while (game->y < game->ray.draw_end)
	{
		draw_textures(game);
		game->y++;
	}
}

void	raycasting(t_game *game)
{
	game->x = 0;
	while (game->x < S_W)
	{
		draw_ceiling_floor(game, S_H / 2, S_H, game->ceilfloor.floor_color);
		draw_ceiling_floor(game, 0, S_H / 2, game->ceilfloor.ceil_color);
		game->ray.camera_x = 2 * game->x / (double)S_W - 1;
		game->ray.ray_x = game->player.dir_x
			+ game->player.plane_x * game->ray.camera_x;
		game->ray.ray_y = game->player.dir_y
			+ game->player.plane_y * game->ray.camera_x;
		game->ray.map_x = (int)game->player.x;
		game->ray.map_y = (int)game->player.y;
		if (game->ray.ray_x == 0)
			game->ray.deltadist_x = 1e30;
		else
			game->ray.deltadist_x = fabs(1 / game->ray.ray_x);
		if (game->ray.ray_y == 0)
			game->ray.deltadist_y = 1e30;
		else
			game->ray.deltadist_y = fabs(1 / game->ray.ray_y);
		raycasting2(game);
		game->x++;
	}
}
