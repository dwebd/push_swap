/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 02:53:57 by dimirzoe          #+#    #+#             */
/*   Updated: 2024/09/22 13:57:22 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, char specifier)
{
	int	count;

	count = 0;
	if (nbr > 15)
	{
		count += ft_puthex((nbr / 16), specifier);
		count += ft_puthex((nbr % 16), specifier);
	}
	if (nbr > 0 && nbr <= 9)
		count += ft_putchar(nbr + '0');
	if (nbr >= 10 && nbr <= 15)
	{
		if (specifier == 'x')
			count += ft_putchar(nbr - 10 + 'a');
		else if (specifier == 'X')
			count += ft_putchar(nbr - 10 + 'A');
	}
	return (count);
}
