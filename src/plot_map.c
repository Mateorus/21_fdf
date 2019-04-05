/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:38:14 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/05 15:28:12 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_map(t_win *win)
{
	size_t	i;
	t_point	*p;
	t_point	*pnext;
	t_list	*tmp;

	centr(win);
	tmp = win->map;
	while (tmp)
	{
		p = tmp->content;
		pnext = tmp->next ? tmp->next->content : 0;
		i = -1;
		while (++i < tmp->content_size)
		{
			if (i < tmp->content_size - 1)
				put_line_bresenham(p[i], p[i + 1], win->ptr);
			if(pnext && i < tmp->next->content_size)
				put_line_bresenham(p[i], pnext[i], win->ptr);
		}
		tmp = tmp->next;
	}
}
