/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:38:25 by fishaq            #+#    #+#             */
/*   Updated: 2024/09/14 16:11:32 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	word_count(char *s, char c)
// {
// 	int		count;
// 	int		j;
// 	bool	inside_word;

// 	count = 0;
// 	j = 0;
// 	while (s[j])
// 	{
// 		inside_word = false;
// 		while (s[j] == c)
// 			j++;
// 		while (s[j] != c && s[j])
// 		{
// 			if (!inside_word)
// 			{
// 				count++;
// 				inside_word = true;
// 			}
// 			j++;
// 		}
// 	}
// 	return (count);
// }
// size_t	word_count(const char *s, char c)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			count++;
// 			while (*s && *s != c)
// 				s++;
// 		}
// 		else
// 			s++;
// 	}
// 	return (count);
// }

// static	char	*get_next_word(char *str, char c)
// {
// 	static int	i = 0;
// 	char		*word;
// 	int			len;
// 	int			j;

// 	j = 0;
// 	len = 0;
// 	while (str[i] == c)
// 		i++;
// 	while ((str[i + len] != c) && str[i + len])
// 		len++;
// 	word = malloc(sizeof(char) * (size_t)(len + 1));
// 	if (!word)
// 		return (NULL);
// 	while ((str[i] != c) && str[i])
// 		word[j++] = str[i++];
// 	word[j] = '\0';
// 	return (word);
// }

// char	**my_split(char *str, char s)
// {
// 	int		countword;
// 	char	**word;
// 	int		i;

// 	i = 0;
// 	countword = word_count(str, s);
// 	if (!countword)
// 		exit(1);
// 	word = (char **)malloc((size_t)(countword + 1) * sizeof(char *));
// 	if (!word)
// 		return (NULL);
// 	while (countword-- > 0)
// 	{
// 		word[i++] = get_next_word(str, s);
// 	}
// 	word[i] = NULL;
// 	return (word);
// }


static size_t	ft__strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft__strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft__strlen(s1);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	else
	{
		ft_strlcpy(dup, s1, len + 1);
		return (dup);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;
	int		i;
	int		substrlen;

	if (!s)
		return (NULL);
	s_len = ft__strlen(s);
	if (start >= (unsigned int)s_len)
		return (ft_strdup(""));
	substrlen = len;
	if (start + len > s_len)
		substrlen = s_len - start;
	result = (char *)malloc((substrlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < substrlen)
	{
		result[i] = s[start + i];
		i++;
	}
	result[substrlen] = '\0';
	return (result);
}


char	**ft_free(char **str, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		if (str[j] == NULL)
		{
			while (i >= 0)
			{
				if (str[i] != NULL)
					free(str[i]);
				i--;
			}
			free(str);
			return (NULL);
		}
		j--;
	}
	return (str);
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

char **my_split(const char *s, char c)
{
	int			i;
	size_t		lettercounter;
	char		**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			lettercounter = 0;
			while (*s && *s != c && ++lettercounter)
				s++;
			split[i] = ft_substr(s - lettercounter, 0, lettercounter);
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (ft_free(split, i - 1));
}
