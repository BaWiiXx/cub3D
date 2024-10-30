/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:50:29 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/30 17:47:35 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_open_texture(char *str, t_game *data, char **split)
{
	int	tmp;

	tmp = open(str, O_RDONLY);
	if (tmp < 0 || tmp > 1024)
	{
		free_tab(split);
		exit_free_all("error: texture can't be load\n", data);
		return (0);
	}
	close(tmp);
	return (1);
}

char	**cpy_tab(t_game *data)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc(1, sizeof(char *) * (data->map.line - data->map.start_map));
	if (!map)
		exit_free_all("error: empty map\n", data);
	while (data->map.map[i])
	{
		map[i] = ft_strdup(data->map.map[i]);
		data->map.line_cpy_tab++;
		i++;
	}
	return (map);
}

static int	flood_fill_zero(char **map, int x, int y, t_game *game)
{
	if (y < 0 || y >= game->map.line_cpy_tab \
	|| x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == 'C')
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '0' || map[y][x] == ' ')
		map[y][x] = 'C';
	if (flood_fill_zero(map, x + 1, y, game)
		|| flood_fill_zero(map, x - 1, y, game)
		|| flood_fill_zero(map, x, y + 1, game)
		|| flood_fill_zero(map, x, y - 1, game))
		return (1);
	return (0);
}

void	check_zero(t_game *game, char **map_cpy)
{
	int	i;
	int	j;

	j = 0;
	while (map_cpy && map_cpy[j])
	{
		i = 0;
		while (map_cpy[j][i])
		{
			if (map_cpy[j][i] == '0')
			{
				if (flood_fill_zero(map_cpy, i, j, game) == 1)
				{
					free_tab(map_cpy);
					exit_free_all("error: part of the map is open\n", game);
				}
			}
			i++;
		}
		j++;
	}
	free_tab(map_cpy);
}
