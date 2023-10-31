/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:12:41 by lferro            #+#    #+#             */
/*   Updated: 2023/10/31 17:41:52 by lferro           ###   ########.fr       */
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
		{
			free(buf);
			return (NULL);
		}
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

char	*get_residual(char *stash)
{
	int		i;
	int		j;
	char	*residual;

	i = 0;
	j = 0;
	if (!stash)
		return (ft_strdup(""));
	residual = malloc(ft_strlen(stash) * sizeof(char));
	if (!residual)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i])
		residual[j++] = stash[i++];
	residual[j] = 0;
	return (residual);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = line_read(fd, buf, stash);
	free(buf);
	buf = 0;
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = get_residual(line);
	line = sub_line(line);
	if (strcmp(line, "") == 0)
	{
		free(line);
		free(stash);
		return NULL;
	}
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);

// 	char	*str;
// 	while((str = get_next_line(fd)))
// 		printf("%s", str);
// 	close(fd);



// 	return (0);
// }
