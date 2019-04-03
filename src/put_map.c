/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:38:14 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 18:40:08 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	balance(t_list *map)
{
	t_list	*tmp;
	size_t	i;
	size_t	scale_x;
	size_t	scale_y;

	tmp = map;
	scale_x = 0;
	scale_y = 0;
	while (tmp)
	{
		if (tmp->content_size > scale_x)
			scale_x = tmp->content_size;
		scale_y++;
		tmp = tmp->next;
	}
	scale_x = WIN_WIDTH * WIN_SCALE / scale_x;
	scale_y = WIN_HEIGHT * WIN_SCALE / scale_y;
	tmp = map;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x *= scale_x;
			((t_point*)tmp->content)[i].y *= scale_y;
			((t_point*)tmp->content)[i].x += (WIN_WIDTH - (WIN_SCALE * WIN_WIDTH)) / 2;
			((t_point*)tmp->content)[i].y += (WIN_HEIGHT - (WIN_SCALE * WIN_HEIGHT)) / 2;
		}
		tmp = tmp->next;
	}
}

void	put_map(t_win *win)
{
	size_t	i;
	t_point	*p;
	t_list	*tmp;

	tmp = win->map;
	balance(tmp);
	while (tmp)
	{
		i = -1;
		p = tmp->content;
		while (++i < tmp->content_size)
			mlx_pixel_put(g_srv.mlx_ptr, win->ptr, p[i].x, p[i].y, p[i].color);
		tmp = tmp->next;
	}
}
