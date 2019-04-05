/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:34:25 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/05 15:27:50 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*get_ps(char *s, size_t *size)
{
	size_t	i;
	t_point	*p;

	*size = 0;
	i = -1;
	while (s[++i])
	{
		if (ft_isdigit(s[i]))
		{
			(*size)++;
			while (ft_isdigit(s[i]))
				i++;
			i--;
		}
	}
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

static void		centr_map(t_win *win)
{
	size_t	i;
	size_t	j;
	size_t	scale;
	t_list	*tmp;
	t_point	pad;

	scale = win->map_w > win->map_h ? WIN_WIDTH * WIN_SCALE / win->map_w :
									WIN_HEIGHT * WIN_SCALE / win->map_h;
	pad.x = (WIN_WIDTH - scale * (win->map_w - 1)) / 2;
	pad.y = (WIN_HEIGHT - scale * (win->map_h - 1)) / 2;
	tmp = win->map;
	j = 0;
	while (tmp)
	{
		i = -1;
		while(++i < tmp->content_size)
		{
			((t_point*)tmp->content)[i].x = scale * i + pad.x;
			((t_point*)tmp->content)[i].y = scale * j + pad.y;
		}
		j++;
		tmp = tmp->next;
	}
}

void			get_map(char **argv, t_win *win)
{
	int		fd;
	int		res;
	size_t	y;
	size_t	x;
	char	*s;

	while (*++argv)
	{
		ft_assert((fd = open(*argv, O_RDONLY)) == -1, 0);
		win->map = NULL;
		y = 0;
		while ((res = get_next_line(fd, &s)) > 0)
		{
			ft_lstadd(&win->map, ft_lstnew(0, 0));
			win->map->content = get_ps(s, &x);
			win->map->content_size = x;
			win->map_w = x > win->map_w ? x : win->map_w;
			free(s);
			y++;
		}
		ft_assert(res == -1, "get_next_line() failed\n");
		win->map_h = y;
		centr_map(win);
		win++;
		close(fd);
	}
}
