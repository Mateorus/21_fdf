/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:18:44 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/03 20:28:23 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	l = f(lst);
	tmp = l;
	while (lst->next)
	{
		lst = lst->next;
		if (!(l->next = f(lst)))
		{
			free(l->next);
			return (NULL);
		}
		l = l->next;
	}
	return (tmp);
}
