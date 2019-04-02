/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:11:00 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/30 19:55:00 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char		*str;
	long long	i;
	size_t		counter;

	i = n;
	counter = 1;
	while ((i /= 10))
		counter++;
	if (!(str = (n < 0 ? malloc(sizeof(*str) * (counter + 2))
					: malloc(sizeof(*str) * (counter + 1)))))
		return (NULL);
	n < 0 ? (str[++counter] = 0)
			: (str[counter] = 0);
	i = n;
	i = (n < 0 ? -i : i);
	while (counter--)
	{
		str[counter] = i % 10 + '0';
		i /= 10;
	}
	if (n < 0)
		str[++counter] = '-';
	return (str);
}
