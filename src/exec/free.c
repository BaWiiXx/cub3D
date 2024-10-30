/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:33 by egomez            #+#    #+#             */
/*   Updated: 2024/10/24 09:58:24 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_all(t_game *game)
{
	if (game)
	{
		if (game->map.all_map)
			free_tab(game->map.all_map);
		if (game->texture.texture[0])
			mlx_delete_image(game->map.mlx, game->texture.texture[0]);
		if (game && game->texture.texture[1])
			mlx_delete_image(game->map.mlx, game->texture.texture[1]);
		if (game && game->texture.texture[2])
			mlx_delete_image(game->map.mlx, game->texture.texture[2]);
		if (game && game->texture.texture[3])
			mlx_delete_image(game->map.mlx, game->texture.texture[3]);
		if (game && game->texture.path[0])
			mlx_delete_texture(game->texture.path[0]);
		if (game && game->texture.path[1])
			mlx_delete_texture(game->texture.path[1]);
		if (game && game->texture.path[2])
			mlx_delete_texture(game->texture.path[2]);
		if (game && game->texture.path[3])
			mlx_delete_texture(game->texture.path[3]);
		if (game && game->map.img)
			mlx_delete_image(game->map.mlx, game->map.img);
		if (game && game->map.mlx)
			mlx_close_window(game->map.mlx);
	}
}
