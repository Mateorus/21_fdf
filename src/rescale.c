/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:01:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/05 15:19:36 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_win *win)
{
	size_t	i;
	t_point	*p;
	t_list	*tmp;

	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->content_size)
		{
			p[i].x +=
		}
		tmp = tmp->next;
	}
}

void	zoom_out(t_win *win)
{
	
}
