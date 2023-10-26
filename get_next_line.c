/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:42 by lferro            #+#    #+#             */
/*   Updated: 2023/10/26 17:58:33 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char	*get_next_line(int fd)
{
	size_t			bytes_read;
	char			*buf;
	char			*print;
	static t_stavar	s;

	bytes_read = 1;
	buf = malloc(BUFFER_SIZE * sizeof(char));

	s.j = 0;
	while ((bytes_read) > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);

		buf[bytes_read] = '\0';
		while (buf[s.i] && buf[s.i] != '\n')
		{
			ft_strjoin(print, buf);
			s.i++;
		}
		s.i = 0;
	}
	return (print);
}

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);

	printg("%s", get_next_line(fd));

	return (0);
}
