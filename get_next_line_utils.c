/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:46:04 by lferro            #+#    #+#             */
/*   Updated: 2023/10/31 17:41:55 by lferro           ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}



// int	read_fd(int fd, char *buf, char **stash)
// {
// 	size_t	b_read;

// 	b_read = 1;
// 	while (b_read > 0 && has_newline(*stash) == 0)
// 	{
// 		b_read = read(fd, buf, BUFFER_SIZE);
// 		if (b_read < 0)
// 		{
// 			// free(*stash);
// 			return (0);
// 		}
// 		else if (b_read == 0)
// 			break ;
// 		buf[b_read] = 0;
// 		*stash = ft_strjoin_f(*stash, buf);
// 	}
// 	// free(buf);
// 	buf = 0;
// 	return (b_read);
// }




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
	// free(s1);
	return (res);
}


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	start = (size_t)start;
	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (i < start && *s)
		i++;
	while (i >= start && i < len + start)
		res[j++] = s[i++];
	res[j] = 0;
	return (res);
}
