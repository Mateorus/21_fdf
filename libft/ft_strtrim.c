/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:53:11 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/30 14:16:31 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	str = (char*)s + len;
	while (len)
	{
		if (!ft_isspace(*(str - 1)))
			break ;
		str--;
	}
	return (ft_strsub(s, 0, str - s));
}
