/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/15 15:03:54 by gstiedem         ###   ########.fr       */
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

static void		change_alt(t_fpoint *p, float alt_factor)
{
	p->z *= alt_factor;
}

void			morph(t_fpoint *p, t_win *win)
{
	change_alt(p, win->alt);
	rotate_xyz(p, win->rad);
	zoom(p, win->zoom);
}
