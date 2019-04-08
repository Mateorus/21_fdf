/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:01:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/08 18:00:20 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_win *win)
{
	win->scale += !win->scale ? 1 : ceil(win->scale * RESCALE_FACTOR);
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}

void	zoom_out(t_win *win)
{
	win->scale -= ceil(win->scale * RESCALE_FACTOR);
	mlx_clear_window(g_srv.mlx_ptr, win->ptr);
	plot_map(win);
}
