/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:22:09 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/27 17:41:00 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				p;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	p = 0;
	while (n--)
	{
		if (*str1 != *str2)
		{
			p = *str1 - *str2;
			break ;
		}
		str1++;
		str2++;
	}
	return (p);
}
