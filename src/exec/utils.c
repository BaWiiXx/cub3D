/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:45:29 by egomez            #+#    #+#             */
/*   Updated: 2024/10/10 18:45:32 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate2(t_game *game)
{
	if (mlx_is_key_down(game->map.mlx, MLX_KEY_RIGHT))
	{
		game->player.old_dirx = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROTATE_SPEED)
			- game->player.dir_y * sin(ROTATE_SPEED);
		game->player.dir_y = game->player.old_dirx * sin(ROTATE_SPEED)
			+ game->player.dir_y * cos(ROTATE_SPEED);
		game->player.old_planex = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(ROTATE_SPEED)
			- game->player.plane_y * sin(ROTATE_SPEED);
		game->player.plane_y = game->player.old_planex * sin(ROTATE_SPEED)
			+ game->player.plane_y * cos(ROTATE_SPEED);
	}
}
