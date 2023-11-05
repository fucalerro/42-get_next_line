/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:48:21 by lferro            #+#    #+#             */
/*   Updated: 2023/11/05 10:10:05 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# define DUP_MODE 0
# define CHR_MODE 1

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_get_residual
{
	int		i;
	int		j;
	char	*residual;
}			t_get_residual;

char		*freeyator(char **s);
char		*strdup_or_strchr(const char *s, int mode, int c);
size_t		ft_strlen(const char *s);
// char		*ft_strdup(const char *s);
// char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*sub_line(char *line);
char		*get_residual(char *stash);
char		*get_next_line(int fd);
char		*line_read(int fd, char *buf, char *stash);

#endif
