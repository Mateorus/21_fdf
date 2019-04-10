/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:34:41 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/09 19:07:03 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

volatile t_srv	g_srv;

void	init(int size, t_win *win)
{
	while (size--)
	{
		ft_assert(!(win->ptr = mlx_new_window(g_srv.mlx_ptr, WIN_WIDTH,
					WIN_HEIGHT, __FILE__)), "mlx_new_window() failed\n");
		g_srv.win_opened++;
		win->p.color = STD_COLOR;
		mlx_hook(win->ptr, 2, 0, key_press, win);
		mlx_hook(win->ptr, 3, 0, key_release, win);
		mlx_hook(win->ptr, 4, 0, mouse_press, win);
		mlx_hook(win->ptr, 5, 0, mouse_releas, win);
		mlx_hook(win->ptr, 6, 0, mouse_move, win);
		mlx_hook(win->ptr, 12, 0, win_expose, win);
		mlx_hook(win->ptr, 17, 0, win_close, win);
		win++;
	}
}

int		main(int argc, char **argv)
{
	t_win	win[MAX_WINDOWS];
	int		i;

	ft_assert(argc < 2, "Usage: ./fdf <input_file> [input_file] ...\n");
	ft_assert(argc > 11, "Error: too much parameters - maximum: 10\n");
	ft_assert(!(g_srv.mlx_ptr = mlx_init()), "mlx_init() failed\n");
	ft_bzero(win, sizeof(win));
	get_map(argv, win);
	init(--argc, win);
	i = -1;
	while (++i < argc)
	{
		centr(&win[i]);
		plot_map(&win[i]);
	}
	mlx_loop(g_srv.mlx_ptr);
	return (0);
}
