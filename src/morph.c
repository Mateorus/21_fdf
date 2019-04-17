/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/17 14:01:19 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotate_xyz(t_fpoint *p, t_fpoint rad)
{
	t_fpoint	prev;

		prev.x = p->x;
		prev.y = p->y;
		prev.z = p->z;
		p->y = prev.y * cos(rad.x) - prev.z * sin(rad.x);
		p->z = prev.y * sin(rad.x) + prev.z * cos(rad.x);
		prev.z = p->z;
		p->x = prev.x * cos(rad.y) - prev.z * sin(rad.y);
		p->z = -prev.x * sin(rad.y) + prev.z * cos(rad.y);
		prev.x = p->x;
		prev.y = p->y;
		p->x = prev.x * cos(rad.z) - prev.y * sin(rad.z);
		p->y = prev.x * sin(rad.z) + prev.y * cos(rad.z);
}

static void		zoom(t_fpoint *p, float zoom_factor)
{
	p->x *= zoom_factor;
	p->y *= zoom_factor;
	p->z *= zoom_factor;
}

static void		trans(t_fpoint *p, t_fpoint trans_factor)
{
	p->x += trans_factor.x;
	p->y += trans_factor.y;
	p->z += trans_factor.z;
}

static void		dye_map(t_fpoint *p, t_win *win)
{
	if (p->z > win->alt_max * 0.7)
		p->color = win->color3;
	else if (p->z < win->alt_max * 0.7 && p->z > win->alt_max * 0.4)
		p->color = win->color2;
	else if (p->z < 0)
		p->color = win->color0;
	else
		p->color = win->color1;
}

void			morph(t_fpoint *p, t_win *win)
{
	dye_map(p, win);
	trans(p, win->trans);
	p->z *= win->alt;
	rotate_xyz(p, win->rad);
	zoom(p, win->zoom);
}
