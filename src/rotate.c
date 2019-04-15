/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/15 10:13:44 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotate_xyz(t_fpoint *p, float xr, float yr, float zr)
{
	t_fpoint	prev;

		prev.x = p->x;
		prev.y = p->y;
		prev.z = p->z;
		p->x = prev.x;
		p->y = prev.y * cos(xr) - prev.z * sin(xr);
		p->z = prev.y * sin(xr) + prev.z * cos(xr);
		p->x = prev.x * cos(yr) - p->z * sin(yr);
		p->z = -prev.x * sin(yr) + p->z * cos(yr);
		p->x = p->x * cos(zr) - p->y * sin(zr);
		p->y = p->x * sin(zr) + p->y * cos(zr);
}

void			rotate(t_win *win, float xr, float yr, float zr)
{
	size_t		i;
	t_list		*cur;
	t_list		*cpy;
	t_fpoint	p;

	cur = win->map;
	cpy = win->map_copy;
	while (cur)
	{
		i = -1;
		while (++i < cur->content_size)
		{
			p.x = ((t_fpoint*)cpy->content)[i].x;
			p.y = ((t_fpoint*)cpy->content)[i].y;
			p.z = ((t_fpoint*)cpy->content)[i].z;
			rotate_xyz(&p, xr, yr, zr);
			((t_fpoint*)cur->content)[i].x = p.x;
			((t_fpoint*)cur->content)[i].y = p.y;
			((t_fpoint*)cur->content)[i].z = p.z;
		}
		cur = cur->next;
		cpy = cpy->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}
