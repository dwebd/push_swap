#include "push_swap.h"

size_t	ft_strlen(const char *s)
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

	len = ft_strlen(src);
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

	len = ft_strlen(s1);
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
	s_len = ft_strlen(s);
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
