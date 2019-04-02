/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeargv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:25:47 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/06 23:58:15 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freeargv(char ***argv, size_t n)
{
	while (n--)
		ft_strdel((*argv) + n);
	ft_memdel((void**)argv);
	return (NULL);
}
