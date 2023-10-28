/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:46:04 by lferro            #+#    #+#             */
/*   Updated: 2023/10/28 18:15:23 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ds;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ds = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (ds == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ds[i] = s[i];
		i++;
	}
	ds[i] = 0;
	return (ds);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	*i;

	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	i = (size_t[]){0, ft_strlen(s1) + ft_strlen(s2)};
	res = malloc(sizeof(char) * (i[1] + 1));
	if (res == NULL)
		return (NULL);
	while (*s1)
		res[i[0]++] = *s1++;
	while (*s2)
		res[i[0]++] = *s2++;
	res[i[0]++] = 0;
	return (res);
}
