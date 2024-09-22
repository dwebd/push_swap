/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ultil.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:44:06 by fishaq            #+#    #+#             */
/*   Updated: 2023/08/23 16:25:50 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ps1;
	char	*ptr;
	int		tlen;

	if (!s1 && !s2)
		return (0);
	tlen = ft_strlen(s1) + ft_strlen(s2);
	ps1 = malloc(sizeof(char) * (tlen + 1));
	if (!ps1)
		return (NULL);
	ptr = ps1;
	if (s1)
		while (*s1)
			*ptr++ = *s1++;
	if (s2)
		while (*s2)
			*ptr++ = *s2++;
	*ptr = '\0';
	return (ps1);
}
