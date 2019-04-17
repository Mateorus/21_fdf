/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:04 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/17 14:12:21 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_map_color(int keycode, t_win *win)
{
	if (keycode == ONE)
	{
		win->color0 = BLUE;
		win->color1 = GREEN;
		win->color2 = BROWN;
		win->color3 = WHITE;
	}
	else if (keycode == TWO)
	{
		win->color0 = RED;
		win->color1 = SILVER;
		win->color2 = PURPLE;
		win->color3 = CYAN;
	}
	else if (keycode == THREE)
	{
		win->color0 = GRAY;
		win->color1 = WHITE;
		win->color2 = WHITE;
		win->color3 = WHITE;
	}
}
