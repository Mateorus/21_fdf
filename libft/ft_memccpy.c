/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:06:39 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/24 15:47:51 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char tmp;
	unsigned char *dstp;
	unsigned char *srcp;

	tmp = (unsigned char)c;
	dstp = (unsigned char*)dst;
	srcp = (unsigned char*)src;
	while (n)
	{
		*dstp = *srcp;
		if (*srcp == tmp)
			return (dstp + 1);
		srcp++;
		dstp++;
		n--;
	}
	return (NULL);
}
