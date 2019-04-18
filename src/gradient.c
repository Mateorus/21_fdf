/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:21:44 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/18 13:41:38 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	light(int start, int end, float percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int			gradient(int str_color, int end_color, int distance, int len)
{
	int		red;
	int		green;
	int		blue;
	int		gamma;
	float	percent;

	if (str_color == end_color)
		return (str_color);
	percent = (len - distance) / (float)len;
	gamma = light((str_color >> 24) & 0xFF, (end_color >> 24) & 0xFF, percent);
	red = light((str_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, percent);
	green = light((str_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, percent);
	blue = light(str_color & 0xFF, end_color & 0xFF, percent);
	return ((gamma << 24) | (red << 16) | (green << 8) | blue);
}
