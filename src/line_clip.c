/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_clip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:00:29 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/10 16:54:00 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		getcode(t_point p)
{
	int	code;

	code = INSIDE;
	code |= p.x < -WIN_WIDTH / 2 ? LEFT : 0;
	code |= p.x >= WIN_WIDTH / 2 ? RIGHT : 0;
	code |= p.y < -WIN_HEIGHT / 2 ? TOP : 0;
	code |= p.y >= WIN_HEIGHT / 2 ? BOTTOM : 0;
	return (code);
}

void	find_interception(t_point *p, t_point incr, t_point diff)
{
	int		d;
	int		flag;
	t_point	edge;

	d = diff.x > diff.y ? -diff.x : -diff.y;
	edge.x = WIN_WIDTH / 2;
	edge.y = WIN_HEIGHT / 2;
	flag = 0;
	if (diff.x < diff.y && ++flag)
	{
		ft_swap(&p->x, &p->y);
		ft_swap(&diff.x, &diff.y);
		ft_swap(&incr.x, &incr.y);
		ft_swap(&edge.x, &edge.y);
	}
	while (p->x < -edge.x || p->x >= edge.x || p->y < -edge.y || p->y >= edge.y)
	{
		p->x += incr.x;
		d += diff.y << 1;
		p->y += d > 0 ? incr.y : 0;
		d -= d > 0 ? diff.x << 1 : 0;
	}
	flag ? ft_swap(&p->x, &p->y) : 0;
}

int		line_clip(t_point *p_a, t_point *p_b, t_point incr, t_point diff)
{
	int	code1;
	int	code2;

	code1 = getcode(*p_a);
	code2 = getcode(*p_b);
	if (code1 == 0 && code2 == 0)
		return (0);
	else if (code1 & code2)
		return (1);
	else
	{
		if (code1 != 0)
			find_interception(p_a, incr, diff);
		else
		{
			incr.x = -incr.x;
			incr.y = -incr.y;
			find_interception(p_b, incr, diff);
		}
	}
	return (0);
}
