/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:48:21 by lferro            #+#    #+#             */
/*   Updated: 2023/11/05 08:49:53 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_str
{
	char	*buf;
	char	*stash;
	char	*line;
}			t_str;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*sub_line(char *line);
char		*get_residual(char *stash);
char		*get_next_line(int fd);
char		*line_read(int fd, char *buf, char *stash);

#endif
