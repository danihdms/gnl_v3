/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <dhaydamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:19 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/11/15 19:42:22 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	if (size >= SIZE_MAX || nmemb >= SIZE_MAX)
		return (NULL);
	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = 0;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*res;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = 0;
	return (res);
}

int	contains_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
