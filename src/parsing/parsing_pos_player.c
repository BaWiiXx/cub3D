/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pos_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:32 by bdany             #+#    #+#             */
/*   Updated: 2024/10/24 11:06:06 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_pos_player(t_game *pos)
{
	int	x;
	int	y;

	y = 0;
	while (pos->map.map[y])
	{
		x = 0;
		while (pos->map.map[y][x])
		{
			if (pos->map.map[y][x] == 'N' || pos->map.map[y][x] == 'S'
				|| pos->map.map[y][x] == 'E' || pos->map.map[y][x] == 'W')
			{
				pos->player.x = x + 0.5;
				pos->player.y = y + 0.5;
				pos->player.orientation = pos->map.map[y][x];
				pos->map.map[y][x] = 48;
				return ;
			}
			x++;
		}
		y++;
	}
	exit_free_all("error: no player position found\n", pos);
}
