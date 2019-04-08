/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:38:14 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/08 19:42:14 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		scale(t_win *win)
{
	size_t	i;
	size_t	j;
	size_t	scale;
	t_list	*tmp;
	t_point	pad;

	scale = win->scale;
	pad.x = (WIN_WIDTH - scale * (win->map_x - 1)) / 2;
	pad.y = (WIN_HEIGHT - scale * (win->map_y - 1)) / 2;
	tmp = win->map;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x = scale * i + pad.x;
			((t_point*)tmp->content)[i].y = scale * j + pad.y;
		}
		j++;
		tmp = tmp->next;
	}
}

void	plot_map(t_win *win)
{
	size_t	i;
	t_point	*p;
	t_point	*pnext;
	t_list	*tmp;

	scale(win);
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
