/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/30 15:12:10 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	flood_fill(char **map, int x, int y, t_game *game)
{
	int	len;

	len = game->map.line_cpy_tab;
	if (game->count_flood > 50000)
		return (1);
	if (y < 0 || y >= len)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if (map[y][x] == '0')
		game->count_flood++;
	map[y][x] = 'F';
	if (flood_fill(map, x + 1, y, game)
		|| flood_fill(map, x - 1, y, game)
		|| flood_fill(map, x, y + 1, game)
		|| flood_fill(map, x, y - 1, game))
		return (1);
	return (0);
}

static char	**no_space_arround_player(t_game *game)
{
	char	**map_cpy;
	int		x;
	int		y;

	map_cpy = cpy_tab(game);
	x = game->player.x;
	y = game->player.y;
	if (flood_fill(map_cpy, x, y, game) == 1)
	{
		free_tab(map_cpy);
		exit_free_all("error: map open or too long\n", game);
	}
	return (map_cpy);
}

static void	while_empty_line(char ***map)
{
	while (**map && ***map == '\0')
		(*map)++;
}

static int	check_map(t_game *data)
{
	int		i;
	char	**map;
	char	**map_cpy;

	i = 0;
	map = data->map.map;
	if (!map)
		return (1);
	while (map[i])
	{
		is_empty_line(map[i], data);
		validate_line(map[i], data);
		i++;
	}
	get_pos_player(data);
	if (data->texture.direction != 1)
		return (1);
	map_cpy = no_space_arround_player(data);
	check_zero(data, map_cpy);
	return (0);
}

void	parse_map(t_game *data)
{
	while_empty_line(&data->map.map);
	if (check_map(data) == 1)
		exit_free_all("error: zero or two player found\n", data);
}
