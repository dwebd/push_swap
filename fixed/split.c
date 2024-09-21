/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:38:25 by fishaq            #+#    #+#             */
/*   Updated: 2024/09/21 20:02:20 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **split, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		if (split[j] == NULL)
		{
			while (i >= 0)
			{
				if (split[i] != NULL)
					free(split[i]);
				i--;
			}
			free(split);
			return (NULL);
		}
		j--;
	}
	return (split);
}

size_t	ft_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char **my_split(const char *str, char delimeter)
{
	int i;
	int lettercounter;
	char **split;

	if(!str || !(split = (char **)malloc(sizeof(char *) * ft_word_count(str, delimeter) + 1)))
			return(NULL);
	i = 0;
	while (*str)
	{
		if(*str != delimeter)
		{
			lettercounter = 0;
			while (*str && *str != delimeter && ++lettercounter)
				str++;
			split[i] = ft_substr(str - lettercounter, 0, lettercounter);
			i++;
		}
		else
			str++;
	}
	split[i] = NULL;
    return (ft_free(split, i - 1)); 

}

