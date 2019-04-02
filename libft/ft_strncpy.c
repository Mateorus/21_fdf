/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:49:03 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/24 19:54:27 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*copy;

	copy = dst;
	while (len--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (copy);
}
