/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:42 by lferro            #+#    #+#             */
/*   Updated: 2023/10/30 18:34:28 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get a line with '\n' at the end from a str containing '\n'
// Param1:	String containing '\n'
// Return:	a line with \n at the end
char	*ft_get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (i == ft_strlen(str))
		return (ft_strdup(str));
	line = malloc((i + 2) * sizeof(char));
	if (line == 0)
		return (0);
	i = -1;
	while (str[++i] != '\n' && str[i])
		line[i] = str[i];
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// Returns the residual string after the '\n' of str
char	*get_residual(char *str)
{
	int		i;
	int		j;
	char	*residual;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	while (str[i] != '\n' && str[i])
		i++;
	residual = malloc((ft_strlen(str) - i) * sizeof(char));
	if (residual == 0)
		return (0);
	i++;
	while (str[i])
		residual[j++] = str[i++];
	residual[j] = 0;
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
	t_str		s;
	int			b_read;
	char static	*residual;

	if (has_newline(residual) == 1)
	{
		s.line = ft_get_line(residual);
		residual = get_residual(residual);
		return (s.line);
	}
	s.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (s.buf == 0)
	{
		free(s.line);
		free(residual);
		return (0);
	}
	if (fd < 0 || !s.buf || BUFFER_SIZE <= 0 || read(fd, 0 ,0))
	{
		free(s.buf);
		free(residual);
		return (0);
	}
	s.stash = 0;
	b_read = read_fd(fd, s.buf, &s.stash);

	s.line = ft_strjoin_f(residual, ft_get_line(s.stash));
	residual = get_residual(s.stash);
	if (residual == 0)
		free(residual);
	free(s.stash);
	s.stash = 0;
	return (s.line);
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
