/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:45:32 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/11 21:52:09 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_map(t_win *win)
{
	t_list	*tmp;

	tmp = win->map;
	while (tmp)
	{
		ft_lstadd(&win->map_copy, ft_lstnew(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	rev_list(&win->map_copy);
}
