/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:13:30 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 15:17:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pencil(t_point p, void *win_ptr)
{
	mlx_pixel_put(g_srv.mlx_ptr, win_ptr, p.x, p.y, p.color);
}

static void	put_line(t_point p, t_point diff, t_point incr, void *win_ptr)
{
	int	d;
	int	len;
	int	*x;
	int	*y;

	x = diff.x > diff.y ? &p.x : &p.y;
	y = diff.x > diff.y ? &p.y : &p.x;
	len = diff.x > diff.y ? diff.x : diff.y;
	if (diff.x < diff.y)
	{
		ft_swap(&p.x, &p.y);
		ft_swap(&diff.x, &diff.y);
		ft_swap(&incr.x, &incr.y);
	}
	d = -len;
	len++;
	while (len--)
	{
		mlx_pixel_put(g_srv.mlx_ptr, win_ptr, *x, *y, p.color);
		p.x += incr.x;
		d += diff.y << 1;
		p.y += d > 0 ? incr.y : 0;
		d -= d > 0 ? diff.x << 1 : 0;
	}
}

void		put_line_bresenham(t_point p_a, t_point p_b, void *win_ptr)
{
	int		len;
	t_point	diff;
	t_point	incr;

	incr.x = p_b.x - p_a.x >= 0 ? 1 : -1;
	incr.y = p_b.y - p_a.y >= 0 ? 1 : -1;
	diff.x = ft_abs(p_b.x - p_a.x);
	diff.y = ft_abs(p_b.y - p_a.y);
	len = diff.x > diff.y ? diff.x : diff.y;
	if (!len)
	{
		mlx_pixel_put(g_srv.mlx_ptr, win_ptr, p_a.x, p_a.y, p_a.color);
		return ;
	}
	put_line(p_a, diff, incr, win_ptr);
}
