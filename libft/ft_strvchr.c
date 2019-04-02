/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:29:08 by gstiedem          #+#    #+#             */
/*   Updated: 2018/11/30 17:06:02 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strvchr(const char *s, char *arr, size_t n)
{
	if (!s)
		return (NULL);
	return (ft_memvchr(s, arr, n, ft_strlen(s) + 1));
}
