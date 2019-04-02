/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:33:17 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/29 15:39:16 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1);
	if (!(p = (char*)malloc(sizeof(*p) * (len + 1))))
		return (NULL);
	p = ft_memcpy(p, s1, len);
	*(p + len) = 0;
	return (p);
}
