/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:00 by bdany             #+#    #+#             */
/*   Updated: 2024/10/24 11:01:36 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	is_empty_line(char *line, t_game *data)
{
	if (line[0] == '\n' || line[0] == '\0')
		exit_free_all("error: empty line on map\n", data);
}

static int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
		|| c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

static int	check_line(char *str, t_game *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			data->texture.direction += 1;
		if (!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	validate_line(char *line, t_game *data)
{
	if (line[0] != '1' && line[0] != ' ')
		exit_free_all("error: invalid map\n", data);
	if (check_line(line, data) == 1)
		exit_free_all("error: invalid map\n", data);
}
