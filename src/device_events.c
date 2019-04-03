/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:47:44 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 14:53:43 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_win *win)
{
	g_srv.mouse_pressed[button] = 1;
	g_srv.p.x = x;
	g_srv.p.y = y;
	pencil(g_srv.p, win->ptr);
	return (0);
}

int	mouse_releas(int button, int x, int y, t_win *win)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (g_srv.key_pressed[SHIFT] && g_srv.mouse_pressed[1])
		put_line_bresenham(g_srv.p, p, win->ptr); 
	g_srv.mouse_pressed[button] = 0;
	return (0);
}

int	mouse_move(int x, int y, t_win *win)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.color = g_srv.p.color;
	g_srv.mouse_pressed[1] && !g_srv.key_pressed[SHIFT] ? pencil(p, win->ptr) : 0;
	return (0);
}

int	key_press(int keycode, t_win *win)
{
	!g_srv.mouse_pressed[1] ? g_srv.key_pressed[keycode] = 1 : 0;
	keycode == 53 ? win_close(win->ptr) : 0;
	return (0);
}

int	key_release(int keycode, t_win *win)
{
	g_srv.key_pressed[keycode] = 0;
	(void)win;
	return (0);
}
