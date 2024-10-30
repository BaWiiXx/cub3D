/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:01 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/30 15:53:15 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_value(char *line, int *index)
{
	int			value;
	static int	count_value = 0;

	value = 0;
	count_value++;
	if (count_value > 3)
		return (-1);
	if (line[*index] == '\0')
		return (-1);
	while (line[*index] == ' ')
		(*index)++;
	value = ft_atoi(&line[*index]);
	if (value == -1)
		return (-1);
	while (line[*index] >= '0' && line[*index] <= '9')
		(*index)++;
	while (line[*index] == ' ')
		(*index)++;
	if (line[*index] != ',' && line[*index] != '\0')
		return (-1);
	if (line[*index] == '\0')
		count_value = 0;
	(*index)++;
	return (value);
}

static	uint32_t	get_color(char *line, t_game *data)
{
	int	r;
	int	g;
	int	b;
	int	index;

	index = 0;
	r = get_value(line, &index);
	g = get_value(line, &index);
	b = get_value(line, &index);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_free_all("error: wrong value color\n", data);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	set_color(t_game *data, char *line, int *count)
{
	if (line[0] == 'F')
		data->ceilfloor.floor_color = get_color(line + 2, data);
	if (line[0] == 'C')
		data->ceilfloor.ceil_color = get_color(line + 2, data);
	(*count)++;
}
