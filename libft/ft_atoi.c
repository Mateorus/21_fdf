/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:33:02 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/04 17:42:36 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	long long	tmp;
	int			flag;

	flag = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		tmp = num;
		num *= 10;
		num += *str - '0';
		if (num < tmp)
			return (flag == -1 ? 0 : -1);
		str++;
	}
	return (num * flag);
}
