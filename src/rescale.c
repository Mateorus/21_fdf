/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:01:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/14 23:13:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zoom_in(t_win *win)
{
	size_t		i;
	t_list		*tmp;

	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_fpoint*)tmp->content)[i].x *= RESCALE_FACTOR;
			((t_fpoint*)tmp->content)[i].y *= RESCALE_FACTOR;
			((t_fpoint*)tmp->content)[i].z *= RESCALE_FACTOR;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void			zoom_out(t_win *win)
{
	size_t		i;
	t_list		*tmp;

	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_fpoint*)tmp->content)[i].x /= RESCALE_FACTOR;
			((t_fpoint*)tmp->content)[i].y /= RESCALE_FACTOR;
			((t_fpoint*)tmp->content)[i].z /= RESCALE_FACTOR;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void			iso(t_win *win)
{
	size_t		i;
	t_fpoint	p;

	t_list		*tmp;
	t_list		*tmp2;
	tmp = win->map;
	tmp2 = win->map_copy;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			p.x = ((t_fpoint*)tmp->content)[i].x;
			p.y = ((t_fpoint*)tmp->content)[i].y;
			p.z = ((t_fpoint*)tmp->content)[i].z;
			((t_fpoint*)tmp->content)[i].x = (p.x - p.y) * cos(0);
			((t_fpoint*)tmp->content)[i].y = -p.z + (p.x + p.y) * sin(0);
		}
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void			alt_up(t_win *win)
{
	size_t		i;
	t_list		*tmp;

	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_fpoint*)tmp->content)[i].z *= RESCALE_FACTOR;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
}

void			alt_dwn(t_win *win)
{
	size_t		i;
	t_list		*tmp;

	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_fpoint*)tmp->content)[i].z /= RESCALE_FACTOR;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
}
