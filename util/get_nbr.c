/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:28:51 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/14 13:51:54 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_nbr(char **s)
{
	int	ret;

	ret = 0;
	while (**s)
	{
		if ((**s >= '0' && **s <= '9') || **s == '-' || **s == '+')
		{
			if (**s == '0' && (*((*s) + 1) == 'x' || *((*s) + 1) == 'X' ||
								(*((*s) + 1) >= '0' && *((*s) + 1) <= '9')))
			{
				while ((**s >= '0' && **s <= '9') || (**s >= 'a' && **s <= 'f')
					|| (**s >= 'A' && **s <= 'F') || **s == 'x' || **s == 'X')
					(*s)++;
			}
			ret = ft_atoi(*s);
			while ((**s >= '0' && **s <= '9') || **s == '-' || **s == '+')
				(*s)++;
			return (ret);
		}
		else
			(*s)++;
	}
	return (ret);
}
