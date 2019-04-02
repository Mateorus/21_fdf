/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:01:02 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/01 18:37:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_close(void *win_ptr)
{
	if (g_srv.win_opened == 1)
		exit (0);
	mlx_destroy_window(g_srv.mlx_ptr, win_ptr);
	g_srv.win_opened--;
	return (0);
}

int	win_expose(void *win_ptr)
{
	(void)win_ptr;
	return (0);
}
