/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:34:41 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/02 15:09:44 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

volatile t_srv	g_srv;

void	get_maps(char **argv, t_list **mapv)
{
	int		fd;

	while (*++argv)
	{
		fd = open(*argv, O_RDONLY);
		populate_map(fd, mapv++);
		close(fd);
	}
}

void	init(int size, void *win_ptr)
{
	while (size--)
	{
		ft_assert(!(win_ptr = mlx_new_window(g_srv.mlx_ptr, WIN_WIDTH,
					WIN_HEIGHT, __FILE__)), "mlx_new_window() fails\n");
		g_srv.win_opened++;
		mlx_hook(win_ptr, 2, 0, key_press, win_ptr);
		mlx_hook(win_ptr, 3, 0, key_release, win_ptr);
		mlx_hook(win_ptr, 4, 0, mouse_press, win_ptr);
		mlx_hook(win_ptr, 5, 0, mouse_releas, win_ptr);
		mlx_hook(win_ptr, 6, 0, mouse_move, win_ptr);
		mlx_hook(win_ptr, 12, 0, expose, win_ptr);
		mlx_hook(win_ptr, 17, 0, win_close, win_ptr);
		win_ptr++;
	}
}

int		main(int argc, char **argv)
{
	void	*win_ptr[MAX_WINDOWS];
	t_list	**mapv;


	g_srv.p.color = STD_COLOR;
	ft_assert(argc < 2, "Usage: ./fdf <input_file> [input_file] ...\n");
	ft_assert(argc > 11, "Error: too much parameters - maximum: 10\n");
	ft_assert(!(g_srv.mlx_ptr = mlx_init()), "mlx_init() fails\n");
	ft_assert(!(mapv = malloc(sizeof(*mapv) * (--argc + 1))), 0);
	get_maps(argv, mapv);
	init(argc, win_ptr);
	mlx_loop(g_srv.mlx_ptr);
	return (0);
}
