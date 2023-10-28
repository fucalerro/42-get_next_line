/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:42 by lferro            #+#    #+#             */
/*   Updated: 2023/10/28 18:14:54 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get a line with '\n' at the end from a str containing '\n'
// Param1:	String containing '\n'
// Return:	a line with \n at the end
char	*get_linee(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
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
	while (s[i])
		i++;
	if (i == 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	size_t			bytes_read;
	char			*buf;
	char			*stash;
	char			*line;
	static t_stavar	s;
	char			*temp_residual;

	if (has_newline(s.residual) == 1)
	{
		line = get_linee(s.residual);
		temp_residual = get_residual(s.residual);
		free(s.residual);
		s.residual = temp_residual;
		return (line);
	}

	if (fd == 0)
		return (0);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	stash = 0;
	while (bytes_read > 0 && has_newline(stash) == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	if (is_end(buf))
	{
		line = malloc(7 * sizeof(char));
		line = "(null)";
		free(buf);
		// free(s.residual);
		return (line);
	}
	free(buf);
	buf = 0;
	line = get_linee(stash);
	line = ft_strjoin(s.residual, line);
	s.residual = get_residual(stash);
	free(stash);
	return (line);

}


int main()
{
	int	fd;

	fd = open("testfile.txt", O_RDONLY);

	for (int i = 0; i < 8; i++)
		printf("line [%02d]: %s", i + 1, get_next_line(fd));

	// char *next_line = get_next_line(fd);
	// printf("line: %s", next_line);
	// free(next_line);

	return (0);
}
