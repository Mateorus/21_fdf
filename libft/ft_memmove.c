/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:21:03 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/26 20:46:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*copy;

	copy = dst;
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(char*)dst-- = *(char*)src--;
	}
	return (copy);
}
