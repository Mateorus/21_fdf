/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:47:44 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/15 13:53:24 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_win *win)
{
	win->mouse_pressed[button] = 1;
	win->p.x = x;
	win->p.y = y;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		button == SCROLL_UP ? win-> zoom *= RESCALE_FACTOR : 0;
		button == SCROLL_DOWN ? win-> zoom /= RESCALE_FACTOR : 0;
		plot_map(win);
	}
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
	if (keycode == SPACE)
	{
		win->rad.y = 0.785398;
		win->rad.x = 0.95532;
		plot_map(win);
	}
	if ((keycode >= 123 && keycode <= 126) || (keycode >= 24 && keycode <= 33))
	{
		keycode == UP_ARROW ? win->rad.x += ROT_ANGLE : 0;
		keycode == DWN_ARROW ? win->rad.x -= ROT_ANGLE : 0;
		keycode == RGH_ARROW ? win->rad.y += ROT_ANGLE : 0;
		keycode == LFT_ARROW ? win->rad.y -= ROT_ANGLE : 0;
		keycode == RGH_BRACKET ? win->rad.z += ROT_ANGLE : 0;
		keycode == LFT_BRACKET ? win->rad.z -= ROT_ANGLE : 0;
		keycode == PLUS ? win->alt *= RESCALE_FACTOR : 0;
		keycode == MINUS ? win->alt /= RESCALE_FACTOR : 0;
		plot_map(win);
	}
	keycode == ESC ? win_close(win) : 0;
	return (0);
}

int	key_release(int keycode, t_win *win)
{
	win->key_pressed[keycode] = 0;
	return (0);
}
