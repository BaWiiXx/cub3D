/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_of_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:49:19 by bdany             #+#    #+#             */
/*   Updated: 2024/10/29 18:17:59 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_all_of_value(t_game *data)
{
	int	i;

	i = 0;
	data->map.line = 0;
	data->count_flood = 0;
	data->map.line_cpy_tab = 0;
	data->texture.direction = 0;
	data->player.orientation = 0;
	data->map.start_map = 0;
	data->ceilfloor.ceil_color = 0;
	data->ceilfloor.floor_color = 0;
	data->texture.count_c = 0;
	data->texture.count_f = 0;
	data->texture.count_no = 0;
	data->texture.count_we = 0;
	data->texture.count_so = 0;
	data->texture.count_ea = 0;
	while (i < 4)
	{
		data->texture.path[i] = NULL;
		data->texture.texture[i] = NULL;
		i++;
	}
	data->map.mlx = NULL;
	data->map.img = NULL;
}
