/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:47:44 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/01 18:24:33 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, void *win_ptr)
{
	g_srv.mouse_pressed[button] = 1;
	g_srv.p.x = x;
	g_srv.p.y = y;
	pencil(g_srv.p, win_ptr);
	return (0);
}

int	mouse_releas(int button, int x, int y, void *win_ptr)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (g_srv.key_pressed[SHIFT] && g_srv.mouse_pressed[1])
		put_line_bresenham(g_srv.p, p, win_ptr); 
	g_srv.mouse_pressed[button] = 0;
	return (0);
}

int	mouse_move(int x, int y, void *win_ptr)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.color = g_srv.p.color;
	g_srv.mouse_pressed[1] && !g_srv.key_pressed[SHIFT] ? pencil(p, win_ptr) : 0;
	return (0);
}

int	key_press(int keycode, void *win_ptr)
{
	!g_srv.mouse_pressed[1] ? g_srv.key_pressed[keycode] = 1 : 0;
	keycode == 53 ? win_close(win_ptr) : 0;
	return (0);
}

int	key_release(int keycode, void *win_ptr)
{
	g_srv.key_pressed[keycode] = 0;
	(void)win_ptr;
	return (0);
}
