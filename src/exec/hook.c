/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:06 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:51:07 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update(t_game *game)
{
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit(1);
	}
	move(game);
}

void	u_d(t_game *game)
{
	int	x;
	int	y;

	if (mlx_is_key_down(game->map.mlx, MLX_KEY_W))
	{
		x = game->player.x + (game->player.dir_x
				+ WALL_DISTANCE * game->player.dir_x) * SPEED;
		y = game->player.y + (game->player.dir_y
				+ WALL_DISTANCE * game->player.dir_y) * SPEED;
		if (game->map.map[(int)game->player.y][x] == '0')
			game->player.x += game->player.dir_x * SPEED;
		if (game->map.map[y][(int)game->player.x] == '0')
			game->player.y += game->player.dir_y * SPEED;
	}
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_S))
	{
		x = game->player.x - (game->player.dir_x
				+ WALL_DISTANCE * game->player.dir_x) * SPEED;
		y = game->player.y - (game->player.dir_y
				+ WALL_DISTANCE * game->player.dir_y) * SPEED;
		if (game->map.map[(int)game->player.y][x] == '0')
			game->player.x -= game->player.dir_x * SPEED;
		if (game->map.map[y][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_y * SPEED;
	}
}

void	r_l(t_game *game)
{
	int	x;
	int	y;

	if (mlx_is_key_down(game->map.mlx, MLX_KEY_A))
	{
		x = game->player.x + (game->player.dir_y
				+ WALL_DISTANCE * game->player.dir_y) * SPEED;
		y = game->player.y - (game->player.dir_x
				+ WALL_DISTANCE * game->player.dir_x) * SPEED;
		if (game->map.map[(int)game->player.y][x] == '0')
			game->player.x += game->player.dir_y * SPEED;
		if (game->map.map[y][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_x * SPEED;
	}
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_D))
	{
		x = game->player.x - (game->player.dir_y
				+ WALL_DISTANCE * game->player.dir_y) * SPEED;
		y = game->player.y + (game->player.dir_x
				+ WALL_DISTANCE * game->player.dir_x) * SPEED;
		if (game->map.map[(int)game->player.y][x] == '0')
			game->player.x -= game->player.dir_y * SPEED;
		if (game->map.map[y][(int)game->player.x] == '0')
			game->player.y += game->player.dir_x * SPEED;
	}
}

void	rotate(t_game *game)
{
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_LEFT))
	{
		game->player.old_dirx = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROTATE_SPEED)
			- game->player.dir_y * sin(-ROTATE_SPEED);
		game->player.dir_y = game->player.old_dirx * sin(-ROTATE_SPEED)
			+ game->player.dir_y * cos(-ROTATE_SPEED);
		game->player.old_planex = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-ROTATE_SPEED)
			- game->player.plane_y * sin(-ROTATE_SPEED);
		game->player.plane_y = game->player.old_planex * sin(-ROTATE_SPEED)
			+ game->player.plane_y * cos(-ROTATE_SPEED);
	}
	rotate2(game);
}

void	move(t_game *game)
{
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->map.mlx, MLX_KEY_S))
		u_d(game);
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->map.mlx, MLX_KEY_D))
		r_l(game);
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->map.mlx, MLX_KEY_LEFT))
		rotate(game);
	raycasting(game);
}
