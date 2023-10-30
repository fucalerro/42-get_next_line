/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:46:04 by lferro            #+#    #+#             */
/*   Updated: 2023/10/30 18:27:47 by lferro           ###   ########.fr       */
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

char	*ft_strjoin_f(char *s1, char *s2)
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

int	read_fd(int fd, char *buf, char **stash)
{
	size_t	b_read;

	b_read = 1;
	while (b_read > 0 && has_newline(*stash) == 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(*stash);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buf[b_read] = 0;
		*stash = ft_strjoin_f(*stash, buf);
	}
	free(buf);
	buf = 0;
	return (b_read);
}
