/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:26:04 by fishaq            #+#    #+#             */
/*   Updated: 2024/09/22 13:37:14 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_spaces(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_space(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}


char	*concat(int ac, char **av, int *len)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	*len = 1;
	while (i < ac)
	{
		*len += ft_strlen(av[i]) + 1;
		i++;
	}
	str = (char *)ft_calloc((sizeof(char) * (*len)), *len);
	if (!str)
		return (NULL);
	str[*len - 1] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(str, av[i]);
		if (i < ac - 1)
			ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	**get_strings(int ac, char **av)
{
	int		len;
	char	**string;
	char	*word;

	len = 0;
	string = NULL;
	word = NULL;
	if (ac > 2)
		word = concat(ac, av, &len);
	else
		word = av[1];
	string = my_split(word, ' ');
	if (ac > 2)
		free(word);
	return (string);
}

