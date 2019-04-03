/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:01:02 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 14:48:57 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_close(t_win *win)
{
	if (g_srv.win_opened == 1)
		exit (0);
	mlx_destroy_window(g_srv.mlx_ptr, win->ptr);
	g_srv.win_opened--;
	return (0);
}

int	win_expose(t_win *win)
{
	put_map(win);
	return (0);
}
