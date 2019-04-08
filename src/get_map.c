/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:34:25 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/08 19:39:06 by gstiedem         ###   ########.fr       */
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
		win->scale = WIN_WIDTH < WIN_HEIGHT ? WIN_WIDTH * SCALE_FACTOR
			/ win->map_x : WIN_HEIGHT * SCALE_FACTOR / win->map_y;
		win++;
		close(fd);
	}
}
