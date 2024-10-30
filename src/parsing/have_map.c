/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/24 11:06:38 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	size_map(t_game *data)
{
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		exit_error("error: empty map\n");
	while (line != NULL)
	{
		free(line);
		line = get_next_line(data->fd);
		data->map.line++;
	}
	free(line);
}

char	**get_map(t_game *data)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (data->map.line + 1));
	if (!map)
		exit_error("error: empty map\n");
	line = get_next_line(data->fd);
	while (i < data->map.line && line != NULL)
	{
		map[i] = ft_substr(line, 0, strcspn(line, "\n"));
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	map[i] = 0;
	return (map);
}
