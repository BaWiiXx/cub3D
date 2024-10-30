/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:35:47 by bdany             #+#    #+#             */
/*   Updated: 2024/10/18 16:10:17 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(char *buffer, char **s)
{
	char	*ref;

	if (buffer[0] == '\0')
	{
		*s = NULL;
		return ;
	}
	ref = ft_strchr_gnl(buffer, '\n');
	if (ref)
	{
		*s = ft_strnjoin(*s, buffer, ref - buffer + 1);
		ft_strlcpy_gnl(buffer, ref + 1, BUFFER_SIZE);
	}
	else
		*s = ft_strnjoin(*s, buffer, BUFFER_SIZE);
}

char	*get_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*s;

	bytes = 1;
	s = NULL;
	ft_join(buffer, &s);
	while (bytes > 0 && !ft_strchr_gnl(s, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < BUFFER_SIZE)
			buffer[bytes] = '\0';
		if (bytes > 0)
			ft_join(buffer, &s);
	}
	if (s && s[0] == '\0')
		free(s);
	return (s);
}

char	*get_next_line(int fd)
{
	char	*arr;

	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	arr = get_line(fd);
	return (arr);
}
