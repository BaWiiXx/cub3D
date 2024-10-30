/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:40:34 by bdany             #+#    #+#             */
/*   Updated: 2024/10/18 16:09:59 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FD_MAX 1024

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);

#endif
