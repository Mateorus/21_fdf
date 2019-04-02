/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:44:45 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/03 14:46:39 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
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
		write(fd, "-", 1);
	}
	while (counter + 1)
	{
		ft_putchar_fd((i / ft_pow(10, counter)) % 10 + '0', fd);
		counter--;
	}
}
