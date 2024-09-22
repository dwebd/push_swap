#include "push_swap.h"

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
int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
	{
		len++;
	}
	return (len);
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
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!s1)
		return (1);
	while (i < n)
	{
		if (!c2[i] && !c1[i])
			return (0);
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
