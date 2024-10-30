/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:49:23 by egomez            #+#    #+#             */
/*   Updated: 2024/10/23 15:13:41 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_orientation(t_game *game)
{
	if (game->player.orientation == 'N' || game->player.orientation == 'S')
	{
		game->player.plane_x = 1;
		game->player.plane_y = 0;
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	if (game->player.orientation == 'S')
	{
		game->player.plane_x = -1;
		game->player.dir_y = 1;
	}
	if (game->player.orientation == 'E' || game->player.orientation == 'W')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 1;
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	if (game->player.orientation == 'W')
	{
		game->player.plane_y = -1;
		game->player.dir_x = -1;
	}
}

void	init_mlx(t_game *game)
{
	game->map.mlx = mlx_init(S_W, S_H, "Cub3d", 0);
	if (!game->map.mlx)
	{
		ft_putstr_fd("error : failed to initialize mlx\n", 2);
		exit(1);
	}
	game->map.img = mlx_new_image(game->map.mlx, S_W, S_H);
	if (!game->map.img)
	{
		ft_putstr_fd("error : failed to initialize mlx image\n", 2);
		exit(1);
	}
}

void	init_text(t_game *game)
{
	game->texture.texture[0] = \
	mlx_texture_to_image(game->map.mlx, game->texture.path[0]);
	game->texture.texture[1] = \
	mlx_texture_to_image(game->map.mlx, game->texture.path[1]);
	game->texture.texture[2] = \
	mlx_texture_to_image(game->map.mlx, game->texture.path[2]);
	game->texture.texture[3] = \
	mlx_texture_to_image(game->map.mlx, game->texture.path[3]);
}
