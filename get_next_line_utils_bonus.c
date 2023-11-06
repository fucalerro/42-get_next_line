/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:46:04 by lferro            #+#    #+#             */
/*   Updated: 2023/11/06 10:39:17 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*freeyator(char **s)
{
	free(*s);
	*s = 0;
	return (NULL);
}

char	*strdup_or_strchr(const char *s, int mode, int c)
{
	char	*res;
	size_t	i;

	i = -1;
	if (mode == DUP_MODE)
	{
		if (s == NULL)
			return (NULL);
		res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (res == NULL)
			return (NULL);
		i = -1;
		while (s[++i])
			res[i] = s[i];
		res[i] = 0;
		return (res);
	}
	c = (char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	totlen;

	i = 0;
	j = 0;
	totlen = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (totlen + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
