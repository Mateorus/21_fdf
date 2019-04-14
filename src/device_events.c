/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:47:44 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/14 15:07:25 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_win *win)
{
	win->mouse_pressed[button] = 1;
	win->p.x = x;
	win->p.y = y;
	button == SCROLL_UP ? zoom_in(win) : 0;
	button == SCROLL_DOWN ? zoom_out(win) : 0;
	return (0);
}

int	mouse_releas(int button, int x, int y, t_win *win)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (win->key_pressed[SHIFT] && win->mouse_pressed[1])
		put_line_bresenham(win->p, p, win->ptr); 
	win->mouse_pressed[button] = 0;
	return (0);
}

int	mouse_move(int x, int y, t_win *win)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.color = win->p.color;
	win->mouse_pressed[1] && !win->key_pressed[SHIFT] ? pencil(p, win->ptr) : 0;
	return (0);
}

int	key_press(int keycode, t_win *win)
{
	!win->mouse_pressed[1] ? win->key_pressed[keycode] = 1 : 0;
	keycode == SPACE ? iso(win) : 0;
	keycode == UP_ARROW ? rotate_x(win, CLOCKWISE) : 0;
	keycode == DWN_ARROW ? rotate_x(win, C_CLOCKWISE) : 0;
	keycode == LFT_ARROW ? rotate_y(win, C_CLOCKWISE) : 0;
	keycode == RGH_ARROW ? rotate_y(win, CLOCKWISE) : 0;
	keycode == LFT_BRACKET ? rotate_z(win, C_CLOCKWISE) : 0;
	keycode == RGH_BRACKET ? rotate_z(win, CLOCKWISE) : 0;
	keycode == ESC ? win_close(win) : 0;
	keycode == PLUS ? alt_up(win) : 0;
	keycode == MINUS ? alt_dwn(win) : 0;
	return (0);
}

int	key_release(int keycode, t_win *win)
{
	win->key_pressed[keycode] = 0;
	return (0);
}
