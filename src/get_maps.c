/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:34:25 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/15 14:22:06 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fpoint	*get_ps(char *s, size_t *size)
{
	size_t		i;
	t_fpoint	*p;

	*size = count_num(s);
	ft_assert(!(p = malloc(sizeof(*p) * *size)), 0);
	i = -1;
	while (++i < *size)
	{
		p[i].x = 0;
		p[i].y = 0;
		p[i].z = get_nbr(&s);
		p[i].color = STD_COLOR;
	}
	return (p);
}

static void		get_map(int fd, t_win *win)
{
	int			res;
	size_t		y;
	size_t		x;
	char		*s;

		y = 0;
		while ((res = get_next_line(fd, &s)) > 0)
		{
			ft_lstadd(&win->map, ft_lstnew(0, 0));
			win->map->content = get_ps(s, &x);
			win->map->content_size = x;
			win->map_x = x > win->map_x ? x : win->map_x;
			free(s);
			y++;
		}
		ft_assert(res == -1, "get_next_line() failed\n");
		win->map_y = y;
		rev_list(&win->map);
}

static void		centr_map(t_win *win)
{
	size_t		i;
	size_t		j;
	size_t		s;
	t_point		pad;
	t_list		*tmp;

	s = WIDTH > HEIGHT ? HEIGHT * CENTR_FACTOR / win->map_y :
						WIDTH * CENTR_FACTOR / win->map_x;
	pad.x = (WIDTH - s * (win->map_x - 1)) / 2;
	pad.y = (HEIGHT - s * (win->map_y - 1)) / 2;
	tmp = win->map;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_fpoint*)tmp->content)[i].x = -WIDTH / 2.0 + s * i + pad.x;
			((t_fpoint*)tmp->content)[i].y = -HEIGHT / 2.0 + s * j + pad.y;
		}
		j++;
		tmp = tmp->next;
	}
}

static void		copy_map(t_win *win)
{
	t_list		*tmp;

	tmp = win->map;
	while (tmp)
	{
		ft_lstadd(&win->map_copy, ft_lstnew(tmp->content, tmp->content_size
					* sizeof(*tmp)));
		tmp = tmp->next;
	}
	rev_list(&win->map_copy);
}

void			get_maps(char **argv, t_win *win)
{
	int			fd;

	while (*++argv)
	{
		ft_assert((fd = open(*argv, O_RDONLY)) == -1, 0);
		get_map(fd, win);
		centr_map(win);
		copy_map(win);
		win->zoom = 1;
		win->alt = 1;
		win++;
		close(fd);
	}
}
