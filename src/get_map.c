/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:34:25 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 15:36:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*get_ps(char *s, int *size, int y)
{
	int	i;
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
		p[i].x = i;
		p[i].y = y;
		p[i].z = get_nbr(&s);
		p[i].color = STD_COLOR;
	}
	return (p);
}

void			get_map(char **argv, t_win *win)
{
	int		y;
	int		fd;
	int		res;
	char	*s;

	while (*++argv)
	{
		y = 0;
		ft_assert((fd = open(*argv, O_RDONLY)) == -1, 0);
		win->map = NULL;
		while ((res = get_next_line(fd, &s)) > 0)
		{
			ft_lstadd(&win->map, ft_lstnew(0, 0));
			win->map->content = get_ps(s, &res, y++);
			win->map->content_size = res;
			free(s);
		}
		ft_assert(res == -1, "get_next_line() failed\n");
		win++;
		close(fd);
	}
}
