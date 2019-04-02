/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:19:49 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/06 23:58:43 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**argv;
	size_t	w_num;
	size_t	i;
	char	*arr;

	arr = (char[2]) {c, 0};
	if (!s)
		return (NULL);
	w_num = ft_wc(s, c);
	if (!(argv = malloc(sizeof(*argv) * (w_num + 1))))
		return (NULL);
	argv[w_num] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!(argv[i] = ft_strsub(s, 0, ft_strvchr(s, arr, 2) - s)))
				return (ft_freeargv(&argv, i));
			s += ft_strlen(argv[i++]) - 1;
		}
		s++;
	}
	return (argv);
}
