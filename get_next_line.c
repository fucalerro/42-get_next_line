/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:42 by lferro            #+#    #+#             */
/*   Updated: 2023/10/30 11:47:56 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get a line with '\n' at the end from a str containing '\n'
// Param1:	String containing '\n'
// Return:	a line with \n at the end
char	*get_line(char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (i == ft_strlen(str))
		return (ft_strdup(str));
	res = malloc((i + 2) * sizeof(char));
	i = -1;
	while (str[++i] != '\n' && str[i])
		res[i] = str[i];
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

// Returns the residual string after the '\n' of str
char	*get_residual(char *str)
{
	int		i;
	int		j;
	char	*residual;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	residual = malloc((ft_strlen(str) - i) * sizeof(char));
	i++;
	while (str[i])
		residual[j++] = str[i++];
	residual[i] = 0;
	return (residual);
}

int	has_newline(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_end(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	if (i == 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*stash;
	char		*line;
	char static	*residual;
	int			bytes_read;

	if (has_newline(residual) == 1)
	{
		line = get_line(residual);
		residual = get_residual(residual);
		return (line);
	}
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || !buf)
		return (0);
	stash = 0;
	bytes_read = read_fd(fd, buf, &stash);
	free(buf);
	buf = 0;
	if (bytes_read <= 0)
		return (ft_strdup("(null)"));
	line = ft_strjoin_f(residual, get_line(stash));
	residual = get_residual(stash);
	free(stash);
	stash = 0;
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	for (int i = 0; i < 8; i++)
		printf("line [%02d]: %s", i + 1, get_next_line(fd));
	close(fd);
	// char *next_line = get_next_line(fd);
	// printf("line: %s", next_line);
	// free(next_line);
	return (0);
}
