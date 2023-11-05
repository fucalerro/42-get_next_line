/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:12:41 by lferro            #+#    #+#             */
/*   Updated: 2023/11/05 08:49:37 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*line_read(int fd, char *buf, char *stash)
{
	int		bread;
	char	*temp_stash;

	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, buf, BUFFER_SIZE);
		if (bread < 0)
			return (NULL);
		else if (bread == 0)
			break ;
		buf[bread] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp_stash = stash;
		stash = ft_strjoin(temp_stash, buf);
		free(temp_stash);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}


char	*sub_line(char *line)
{
	char	*newline;
	int		i;

	i = 0;
	newline = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i] && line[i] != '\n')
	{
		newline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}
typedef struct s_get_residual
{
	int i;
	int j;
	char *residual;
}	t_get_residual;
char	*get_residual(char *line)
{
	t_get_residual var;

	var.i= 0;
	var.j= 0;
	var.residual = malloc(ft_strlen(line) * sizeof(char));
	if (!line)
		return (ft_strdup(""));
	if (!var.residual)
		return (NULL);
	while (line[var.i] && line[var.i] != '\n')
		var.i++;
	if (line[var.i] == '\n')
		var.i++;
	while (line[var.i])
		var.residual[var.j++] = line[var.i++];
	var.residual[var.j] = 0;
	return (var.residual);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(stash);
		stash = 0;
		return (NULL);
	}
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = line_read(fd, buf, stash);
	free(buf);
	buf = 0;
	if (!line)
	{
		free(stash);
		stash = 0;
		return (NULL);
	}
	res = sub_line(line);
	stash = get_residual(line);
	free(line);
	line = 0;
	if ( *res == '\0')
	{
		free(res);
		free(stash);
		res = 0;
		stash = 0;
		return NULL;
	}
	return (res);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);

// 	char	*str;
// 	while((str = get_next_line(fd)))
// 		printf("%s", str);
// 	close(fd);
// 	free(str);


// 	return (0);
// }
