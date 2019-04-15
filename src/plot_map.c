/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:38:14 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/15 11:48:41 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		img.ptr[*x + WIDTH / 2 + (*y + HEIGHT / 2) * WIDTH] = p.color;
		p.x += incr.x;
		d += diff.y << 1;
		p.y += d > 0 ? incr.y : 0;
		d -= d > 0 ? diff.x << 1 : 0;
	}
}

static void		put_line_addr(t_point p_a, t_point p_b, t_win *win)
{
	int			len;
	t_img		img;
	t_point		diff;
	t_point		incr;

	img.ptr = (int*)mlx_get_data_addr(win->img_ptr, &img.bpp,
										&img.size, &img.endian);
	incr.x = p_b.x - p_a.x >= 0 ? 1 : -1;
	incr.y = p_b.y - p_a.y >= 0 ? 1 : -1;
	diff.x = ft_abs(p_b.x - p_a.x);
	diff.y = ft_abs(p_b.y - p_a.y);
	len = diff.x > diff.y ? diff.x : diff.y;
	if (line_clip(p_a, p_b, img))
		return;
	if (!len)
	{
		img.ptr[p_a.x + WIDTH / 2 + (p_a.y + HEIGHT / 2) * WIDTH] = p_a.color;
		return ;
	}
	put_line(p_a, diff, incr, img);
}

static void		plot_line(t_win *win, t_fpoint *p, t_fpoint *pnext, t_list *tmp)
{
	size_t		i;
	size_t		size;
	size_t		size_n;

	size = tmp->content_size;
	size_n = pnext ? tmp->next->content_size : 0;
	i = -1;
	while (++i < size)
	{
		if (i < size - 1)
			put_line_addr(f_to_i_point(p[i]), f_to_i_point(p[i + 1]), win);
		if(pnext && i < size_n)
			put_line_addr(f_to_i_point(p[i]), f_to_i_point(pnext[i]), win);
	}
}

static void		prepare_map(t_win *win)
{
	size_t		i;
	t_list		*cur;
	t_list		*cpy;
	t_fpoint	p;

	cur = win->map;
	cpy = win->map_copy;
	while (cur)
	{
		i = -1;
		while (++i < cur->content_size)
		{
			p.x = ((t_fpoint*)cpy->content)[i].x;
			p.y = ((t_fpoint*)cpy->content)[i].y;
			p.z = ((t_fpoint*)cpy->content)[i].z;
			morph(&p, win);
			((t_fpoint*)cur->content)[i].x = p.x;
			((t_fpoint*)cur->content)[i].y = p.y;
			((t_fpoint*)cur->content)[i].z = p.z;
		}
		cur = cur->next;
		cpy = cpy->next;
	}
}

void			plot_map(t_win *win)
{
	t_fpoint	*p;
	t_fpoint	*pnext;
	t_list		*tmp;

	tmp = win->map;
	ft_assert(!(win->img_ptr = mlx_new_image(g_srv.mlx_ptr, WIDTH,
				HEIGHT)), "mlx_new_image() failed\n");
	prepare_map(win);
	while (tmp)
	{
		p = tmp->content;
		pnext = tmp->next ? tmp->next->content : 0;
		plot_line(win, p, pnext, tmp);
		tmp = tmp->next;
	}
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	mlx_put_image_to_window(g_srv.mlx_ptr, win->ptr, win->img_ptr, 0, 0);
	mlx_destroy_image(g_srv.mlx_ptr, win->img_ptr);
}
