/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <dhaydamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:09 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/11/15 19:51:14 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	remainder = fill_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_line(remainder);
	if (!line)
		return (NULL);
	remainder = clean_remainder(remainder);
	return (line);
}

char	*fill_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*line;
	int		read_int;

	if (!remainder)
		remainder = ft_calloc(sizeof(char), 1);
	read_int = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!contains_new_line(remainder) && read_int > 0)
	{
		read_int = read(fd, buffer, BUFFER_SIZE);
		if (read_int == -1)
		{
			free(buffer);
			return (remainder);
		}
		buffer[read_int] = 0;
		line = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = line;
	}
	free(buffer);
	return (remainder);
}

char	*get_line(char *remainder)
{
	int		len;
	char	*line;

	if (!remainder[0])
		return (NULL);
	len = 0;
	while (remainder[len] && remainder[len] != '\n')
		len++;
	len++;
	line = ft_calloc(sizeof(char), len + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (remainder[len] && remainder[len] != '\n')
	{
		line[len] = remainder[len];
		len++;
	}
	if (remainder[len] && remainder[len] == '\n')
		line[len++] = '\n';
	return (line);
}

char	*clean_remainder(char *remainder)
{
	char	*final;
	int		len;
	int		i;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	final = ft_calloc(sizeof(char), ft_strlen(remainder) - i + 1);
	if (!final)
		return (NULL);
	len = 0;
	i++;
	while (remainder[i])
		final[len++] = remainder[i++];
	free(remainder);
	return (final);
}
