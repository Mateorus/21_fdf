/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:34:28 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/03 18:35:11 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

# define MAX_WINDOWS	10
# define WIN_WIDTH		750
# define WIN_HEIGHT		500
# define WIN_SCALE		0.9
# define SHIFT			257

# define STD_COLOR		0x00FFFFFF

/*
**************************************TYPES*************************************
*/
typedef struct			s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}						t_point;
typedef struct			s_win
{
	void	*ptr;
	t_list	*map;
}						t_win;
typedef struct			s_srv
{
	void		*mlx_ptr;
	t_point		p;
	int			mouse_pressed[8];
	int			key_pressed[280];
	int			win_opened;
}						t_srv;
extern volatile t_srv	g_srv;
/*
***************************************SRC**************************************
*/
void	get_map(char **argv, t_win *win);
void	put_map(t_win *win);
/*
**______________________________/src/device_events.c____________________________
*/
int		mouse_press(int button, int x, int y, t_win *win);
int		mouse_releas(int button, int x, int y, t_win *win);
int		mouse_move(int x, int y, t_win *win);
int		key_press(int keycode, t_win *win);
int		key_release(int keycode, t_win *win);
/*
**______________________________/src/system_events.c____________________________
*/
int		win_close(t_win *win);
int		win_expose(t_win *win);
/*
**__________________________________/src/paint.c________________________________
*/
void	pencil(t_point point , void *win_ptr);
void	put_line_bresenham(t_point p_a, t_point p_b, void *win_ptr);
/*
***************************************UTIL*************************************
*/
int		get_next_line(const int fd, char **line);
void	ft_assert(int i, char *s);
int		ft_abs(int n);
void	ft_swap(int *a, int *b);
int		get_nbr(char **s);

#endif