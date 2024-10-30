/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:51:41 by bdany             #+#    #+#             */
/*   Updated: 2024/10/18 16:10:44 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j] && j < n)
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	if (!s)
		return (NULL);
	while (*s && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen_gnl(src));
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen_gnl(src));
}
