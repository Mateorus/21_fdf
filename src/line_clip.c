/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_clip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:00:29 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/17 19:55:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		getcode(t_point p)
{
	int	code;

	code = INSIDE;
	code |= p.x < -WIDTH / 2 ? LEFT : 0;
	code |= p.x >= WIDTH / 2 ? RIGHT : 0;
	code |= p.y < -HEIGHT / 2 ? TOP : 0;
	code |= p.y >= HEIGHT / 2 ? BOTTOM : 0;
	return (code);
}

static void		put_line(t_point p, t_point diff, t_point incr, t_img img)
{
	int			d;
	int			len;
	int			*x;
	int			*y;

	x = diff.x >= diff.y ? &p.x : &p.y;
	y = diff.x >= diff.y ? &p.y : &p.x;
	len = diff.x >= diff.y ? diff.x : diff.y;
	if (diff.y > diff.x)
	{
		ft_swap(&p.x, &p.y);
		ft_swap(&diff.x, &diff.y);
		ft_swap(&incr.x, &incr.y);
	}
	d = -len;
	while (len--)
	{
		if (*x >= -WIDTH / 2 && *x < WIDTH / 2 && *y >= -HEIGHT / 2 && *y < HEIGHT / 2)
			img.ptr[*x + WIDTH / 2 + (*y + HEIGHT / 2) * WIDTH] = gradient(p.color,\
					diff.color, len + 1, diff.x);
		p.x += incr.x;
		d += diff.y << 1;
		p.y += d > 0 ? incr.y : 0;
		d -= d > 0 ? diff.x << 1 : 0;
	}
}

int		line_clip(t_point p_a, t_point p_b, t_img img)
{
	int	code1;
	int	code2;
	t_point	incr;
	t_point	diff;

	code1 = getcode(p_a);
	code2 = getcode(p_b);
	incr.x = p_b.x - p_a.x >= 0 ? 1 : -1;
	incr.y = p_b.y - p_a.y >= 0 ? 1 : -1;
	diff.x = ft_abs(p_b.x - p_a.x);
	diff.y = ft_abs(p_b.y - p_a.y);
	diff.color = p_b.color;
	if (code1 == 0 && code2 == 0)
		return (0);
	else if (code1 & code2)
		return (1);
	else
		put_line(p_a, diff, incr, img);
	return (1);
}
