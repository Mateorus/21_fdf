/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:02:58 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/02 17:29:29 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlst	*get_lst(t_fdlst **first, const int fd)
{
	t_fdlst	*tmp;

	tmp = *first;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = malloc(sizeof(t_fdlst))))
		return (NULL);
	tmp->fd = fd;
	tmp->content = NULL;
	tmp->start = NULL;
	tmp->next = *first;
	*first = tmp;
	return (tmp);
}

char	*get_lst_line(t_fdlst *l)
{
	char	*tmp;
	char	*sub;

	if (!l->content || !*l->content)
		return (NULL);
	if ((tmp = ft_strchr(l->content, '\n')))
	{
		*tmp = 0;
		sub = ft_strdup(l->content);
		l->content = tmp + 1;
	}
	else
	{
		sub = ft_strdup(l->content);
		ft_strdel(&l->start);
		l->content = NULL;
	}
	return (sub);
}

void	add_lst_line(t_fdlst *l, char *buf)
{
	char	*tmp;

	if (!l->content)
	{
		l->content = ft_strdup(buf);
		l->start = l->content;
	}
	else if (*buf)
	{
		tmp = ft_strjoin(l->content, buf);
		ft_strdel(&l->start);
		l->content = tmp;
		l->start = l->content;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*first_lst;
	t_fdlst			*lst;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	ssize_t			r;

	if (!line)
		return (-1);
	if (!(lst = get_lst(&first_lst, fd)))
		return (-1);
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		if (r == -1)
			return (-1);
		buf[r] = 0;
		add_lst_line(lst, buf);
		if (ft_isin(buf, '\n', r))
			break ;
	}
	if ((str = get_lst_line(lst)))
		*line = str;
	return (str != 0 ? 1 : 0);
}
