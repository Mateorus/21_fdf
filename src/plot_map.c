/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:38:14 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/10 16:46:14 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_line(t_point p, t_point diff, t_point incr, t_img img)
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
		img.ptr[*x + WIN_WIDTH / 2 + (*y + WIN_HEIGHT / 2) * WIN_WIDTH] = p.color;
		p.x += incr.x;
		d += diff.y << 1;
		p.y += d > 0 ? incr.y : 0;
		d -= d > 0 ? diff.x << 1 : 0;
	}
}

static void	put_line_addr(t_point p_a, t_point p_b, t_win *win)
{
	int		len;
	t_img	img;
	t_point	diff;
	t_point	incr;

	img.ptr = (int*)mlx_get_data_addr(win->img_ptr, &img.bpp,
										&img.size, &img.endian);
	incr.x = p_b.x - p_a.x >= 0 ? 1 : -1;
	incr.y = p_b.y - p_a.y >= 0 ? 1 : -1;
	diff.x = ft_abs(p_b.x - p_a.x);
	diff.y = ft_abs(p_b.y - p_a.y);
	if (line_clip(&p_a, &p_b, incr, diff))
		return;
	diff.x = ft_abs(p_b.x - p_a.x);
	diff.y = ft_abs(p_b.y - p_a.y);
	len = diff.x > diff.y ? diff.x : diff.y;
	if (!len)
	{
		img.ptr[p_a.x + WIN_WIDTH / 2 + (p_a.y + WIN_HEIGHT / 2) * WIN_WIDTH] = p_a.color;
		return ;
	}
	put_line(p_a, diff, incr, img);
}

static void	plot_line(t_win *win, t_point *p, t_point *pnext, t_list *tmp)
{
	size_t	i;
	size_t	size;
	size_t	size_n;

	size = tmp->content_size;
	size_n = pnext ? tmp->next->content_size : 0;
	i = -1;
	while (++i < size)
	{
		if (i < size - 1)
			put_line_addr(p[i], p[i + 1], win);
		if(pnext && i < size_n)
			put_line_addr(p[i], pnext[i], win);
	}
}

void		plot_map(t_win *win)
{
	t_point	*p;
	t_point	*pnext;
	t_list	*tmp;

	tmp = win->map;
	ft_assert(!(win->img_ptr = mlx_new_image(g_srv.mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT)), "mlx_new_image() failed\n");
	while (tmp)
	{
		p = tmp->content;
		pnext = tmp->next ? tmp->next->content : 0;
		plot_line(win, p, pnext, tmp);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(g_srv.mlx_ptr, win->ptr, win->img_ptr, 0, 0);
	mlx_destroy_image(g_srv.mlx_ptr, win->img_ptr);
}
