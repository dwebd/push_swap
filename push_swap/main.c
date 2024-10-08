/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:16:40 by fishaq            #+#    #+#             */
/*   Updated: 2024/09/22 13:34:23 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**str;

	a = NULL;
	b = NULL;
	str = NULL;
	if (ac == 1 || (2 == ac && !av[1][0]))
		return (1);
	check_spaces(ac, av);
	if (ac >= 2)
		str = get_strings(ac, av);
	stack_init(&a, (str), str);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_matrix(str);
	free_stack(&a);
	return (0);
}
