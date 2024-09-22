/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:58:34 by dimirzoe          #+#    #+#             */
/*   Updated: 2023/12/31 04:53:11 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 9)
		count += ft_putchar(nbr + '0');
	else
	{
		count += ft_unbr(nbr / 10);
		count += ft_unbr(nbr % 10);
	}
	return (count);
}
