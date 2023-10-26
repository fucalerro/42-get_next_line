/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:46:04 by lferro            #+#    #+#             */
/*   Updated: 2023/10/26 17:57:44 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	*i;

	i = (size_t[]){0, ft_strlen(s1) + ft_strlen(s2)};
	res = malloc(sizeof(char) * (i[1] + 1));
	if (res == NULL)
		return (NULL);
	while (*s1)
		res[i[0]++] = *s1++;
	while (*s2)
		res[i[0]++] = *s2++;
	res[i[0]++] = 0;
	return (res);
}
