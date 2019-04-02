/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memvchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:58:02 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/30 17:03:40 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memvchr(const void *s, char *arr, size_t n, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (len--)
	{
		if (ft_isin(arr, *str, n))
			return ((void*)str);
		str++;
	}
	return (NULL);
}
