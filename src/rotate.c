/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/14 17:08:05 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(t_win *win, int direction)
{
	size_t		i;
	float		f;
	t_fpoint	prev;
	t_list		*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.y = ((t_fpoint*)tmp->content)[i].y;
			prev.z = ((t_fpoint*)tmp->content)[i].z;
			((t_fpoint*)tmp->content)[i].y = prev.y * cos(f) - prev.z * sin(f);
			((t_fpoint*)tmp->content)[i].z = prev.y * sin(f) + prev.z * cos(f);
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void			rotate_y(t_win *win, int direction)
{
	size_t		i;
	float		f;
	t_fpoint	prev;
	t_list		*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.x = ((t_fpoint*)tmp->content)[i].x;
			prev.z = ((t_fpoint*)tmp->content)[i].z;
			((t_fpoint*)tmp->content)[i].x = prev.x * cos(f) + prev.z * sin(f);
			((t_fpoint*)tmp->content)[i].z = -prev.x * sin(f) + prev.z * cos(f);
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void			rotate_z(t_win *win, int direction)
{
	size_t		i;
	float		f;
	t_fpoint	prev;
	t_list		*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.x = ((t_fpoint*)tmp->content)[i].x;
			prev.y = ((t_fpoint*)tmp->content)[i].y;
			((t_fpoint*)tmp->content)[i].x = prev.x * cos(f) - prev.y * sin(f);
			((t_fpoint*)tmp->content)[i].y = prev.x * sin(f) + prev.y * cos(f);
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}
