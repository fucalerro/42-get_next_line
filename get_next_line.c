/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:42 by lferro            #+#    #+#             */
/*   Updated: 2023/10/27 16:38:56 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get a line with '\n' at the end from a str containing '\n'
// Param1:	String containing '\n'
// Return:	a line with \n at the end
char	*get_line(char const *str)
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
char	*get_residual(char const *str)
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
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	size_t			bytes_read;
	char			*buf;
	char			*print;
	static t_stavar	s;

	if (fd == 0)
		return (0);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	bytes_read = 1;
	print = "";
	while (bytes_read > 0 && has_newline(buf) == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		print = ft_strjoin(print, buf);
	}
	free(buf);
	print = ft_strjoin(s.residual, print);
	s.residual = get_residual(print);
	print = get_line(print);

	return (print);

}

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);

	// printf("%s",get_residual("afeewfwef\nawsfdas"));

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	// printf("line1: %s\n", get_next_line(fd));
	// printf("line2: %s", get_next_line(fd));
	// printf("line3: %s", get_next_line(fd));

	return (0);
}
