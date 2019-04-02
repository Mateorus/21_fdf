/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:14:03 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/03 12:40:22 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	size_t		counter;
	long long	i;

	i = n;
	counter = 0;
	while ((i /= 10))
		counter++;
	i = n;
	if (n < 0)
	{
		i = -i;
		write(1, "-", 1);
	}
	while (counter + 1)
	{
		ft_putchar((i / ft_pow(10, counter)) % 10 + '0');
		counter--;
	}
}
