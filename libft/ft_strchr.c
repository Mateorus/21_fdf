/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:21:06 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/02 17:01:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	if (!tmp)
		return (0);
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp) ;
		tmp++;
	}
	return (0);
}
