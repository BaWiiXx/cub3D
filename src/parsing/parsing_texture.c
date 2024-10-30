/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:40:11 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/30 17:45:57 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1
		|| data->texture.count_no != 1 || data->texture.count_ea != 1
		|| data->texture.count_f != 1 || data->texture.count_c != 1)
		return (1);
	return (0);
}

void	check_for_texture(char **map, t_game *data)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			data->texture.count_no++;
		if (!ft_strncmp(map[i], "SO ", 3))
			data->texture.count_so++;
		if (!ft_strncmp(map[i], "EA ", 3))
			data->texture.count_ea++;
		if (!ft_strncmp(map[i], "WE ", 3))
			data->texture.count_we++;
		if (!ft_strncmp(map[i], "F ", 2))
			data->texture.count_f++;
		if (!ft_strncmp(map[i], "C ", 2))
			data->texture.count_c++;
		i++;
	}
	if (check_count_texture(data) == 1)
	{
		free_tab(map);
		exit_error("error: not enough or too many textures\n");
	}
}

static void	load_image(char *line, mlx_texture_t **path, int *count, \
	t_game *data)
{
	char	**tab;

	*path = NULL;
	tab = ft_split(line, ' ');
	if (tab[1])
	{
		if ((ft_strlen(tab[1]) >= 4) && \
		(ft_strcmp(tab[1] + ft_strlen(tab[1]) - 4, ".png") == 0))
		{
			if (check_open_texture(tab[1], data, tab))
				*path = mlx_load_png(tab[1]);
		}
		else
		{
			free_tab(tab);
			exit_free_all("error: texture can't be load\n", data);
		}
	}
	if (!(*path) || !tab || !line || tab[2])
	{
		free_tab(tab);
		exit_free_all("error: texture can't be load\n", data);
	}
	(*count)++;
	free_tab(tab);
}

static void	load_texture(char **map, t_game *data, int i, int *count)
{
	if (ft_strncmp(map[i], "NO ", 3) == 0)
		load_image(map[i], &data->texture.path[0], count, data);
	else if (ft_strncmp(map[i], "SO ", 3) == 0)
		load_image(map[i], &data->texture.path[1], count, data);
	else if (ft_strncmp(map[i], "EA ", 3) == 0)
		load_image(map[i], &data->texture.path[2], count, data);
	else if (ft_strncmp(map[i], "WE ", 3) == 0)
		load_image(map[i], &data->texture.path[3], count, data);
	else if (ft_strncmp(map[i], "F ", 2) == 0)
		set_color(data, map[i], count);
	else if (ft_strncmp(map[i], "C ", 2) == 0)
		set_color(data, map[i], count);
}

void	check_texture(char **map, t_game *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		load_texture(map, data, i, &count);
		if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3) \
		&& ft_strncmp(map[i], "EA ", 3) && ft_strncmp(map[i], "WE ", 3) \
		&& ft_strncmp(map[i], "F ", 2) && ft_strncmp(map[i], "C ", 2) \
		&& map[i][0] != '\0')
			exit_free_all("error: try to load a bad name texture !\n", data);
		if (count == 6)
			break ;
		i++;
	}
	data->map.start_map = i + 1;
	if (map[i + 1] && map[i + 1][0] != '\0')
		exit_free_all("error: a space is required to seperate \
		the map and the rest of the datas\n", data);
	if (!map[i + 1])
			exit_free_all("error: empty map\n", data);
}
