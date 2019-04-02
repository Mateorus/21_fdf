/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:05:07 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/29 15:10:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;

	if (!*needle)
		return ((char*)haystack);
	ln = ft_strlen(needle);
	while (len && *haystack)
	{
		if (*haystack == *needle && len >= ln
			&& !ft_memcmp(haystack, needle, ln))
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
