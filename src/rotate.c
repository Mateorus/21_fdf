/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/10 10:42:53 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_win *win, int direction)
{
	size_t	i;
	int		tmp_;
	double	f;
	t_point	prev;
	t_list	*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.y = ((t_point*)tmp->content)[i].y;
			prev.z = ((t_point*)tmp->content)[i].z;
			tmp_ = prev.y * cos(f) - prev.z * sin(f);
			((t_point*)tmp->content)[i].y = tmp_;
			tmp_ = prev.y * sin(f) + prev.z * cos(f);
			((t_point*)tmp->content)[i].z = tmp_;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void	rotate_y(t_win *win, int direction)
{
	size_t	i;
	int		tmp_;
	double	f;
	t_point	prev;
	t_list	*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.x = ((t_point*)tmp->content)[i].x;
			prev.z = ((t_point*)tmp->content)[i].z;
			tmp_ = prev.x * cos(f) + prev.z * sin(f);
			((t_point*)tmp->content)[i].x = tmp_;
			tmp_ = -prev.x * sin(f) + prev.z * cos(f);
			((t_point*)tmp->content)[i].z = tmp_;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void	rotate_z(t_win *win, int direction)
{
	size_t	i;
	int		tmp_;
	double	f;
	t_point	prev;
	t_list	*tmp;

	f = direction ? -ROT_ANGLE : ROT_ANGLE;
	tmp = win->map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			prev.x = ((t_point*)tmp->content)[i].x;
			prev.y = ((t_point*)tmp->content)[i].y;
			tmp_ = prev.x * cos(f) - prev.y * sin(f);
			((t_point*)tmp->content)[i].x = tmp_;
			tmp_ = prev.x * sin(f) + prev.y * cos(f);
			((t_point*)tmp->content)[i].y = tmp_;
		}
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}
