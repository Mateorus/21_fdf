/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:28:37 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/27 14:34:04 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnlcpy(char *dst, const char *src, size_t len)
{
	char	*copy;

	copy = dst;
	while (len-- && *src)
		*dst++ = *src++;
	*dst = 0;
	return (copy);
}
