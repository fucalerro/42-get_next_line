/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:48:21 by lferro            #+#    #+#             */
/*   Updated: 2023/10/30 12:18:10 by lferro           ###   ########.fr       */
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

int			has_newline(char *s);
int			read_fd(int fd, char *buf, char **stash);
char		*ft_strdup(const char *s);
char		*ft_get_line(char *str);
int			is_end(char *s);
size_t		ft_strlen(const char *s);
char		*ft_strjoin_f(char *s1, char *s2);
char		*get_next_line(int fd);

#endif
