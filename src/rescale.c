/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:01:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/10 17:10:50 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centr(t_win *win)
{
	size_t	i;
	size_t	j;
	size_t	scale;
	t_point	pad;
	t_list	*tmp;

	scale = WIN_WIDTH > WIN_HEIGHT ? WIN_HEIGHT / win->map_y :
									WIN_WIDTH / win->map_x;
	pad.x = (WIN_WIDTH - scale * (win->map_x - 1)) / 2;
	pad.y = (WIN_HEIGHT - scale * (win->map_y - 1)) / 2;
	tmp = win->map;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x = -WIN_WIDTH / 2 + scale * i + pad.x;
			((t_point*)tmp->content)[i].y = -WIN_HEIGHT / 2 + scale * j + pad.y;

		}
		j++;
		tmp = tmp->next;
	}
}

void	zoom_in(t_win *win)
{
	size_t	i;
	size_t	j;
	t_point	pad;
	t_list	*tmp;

	tmp = win->map;
	pad.x = win->map_x - 1;
	pad.y = win->map_y - 1;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x += 2 * i - pad.x;
			((t_point*)tmp->content)[i].y += 2 * j - pad.y;
		}
		j++;
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void	zoom_out(t_win *win)
{
	size_t	i;
	size_t	j;
	t_point	pad;
	t_list	*tmp;

	tmp = win->map;
	if (((t_point*)tmp->content)[0].x == ((t_point*)tmp->content)[1].x)
		return ;
	pad.x = win->map_x - 1;
	pad.y = win->map_y - 1;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x -= 2 * i - pad.x;
			((t_point*)tmp->content)[i].y -= 2 * j - pad.y;
		}
		j++;
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}
