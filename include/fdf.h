/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:34:28 by gstiedem          #+#    #+#             */
/*   Updated: 2019/04/10 10:36:51 by gstiedem         ###   ########.fr       */
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

# define INSIDE			0
# define LEFT			1
# define RIGHT			2
# define BOTTOM			4
# define TOP			8

# define CLOCKWISE		0
# define C_CLOCKWISE	1
# define ROT_ANGLE		0.1

# define MAX_WINDOWS	10
# define WIN_WIDTH		750
# define WIN_HEIGHT		500
# define CENTR_FACTOR	0.8
# define BPP			4

# define SHIFT			257
# define ESC			53
# define SCROLL_UP		4
# define SCROLL_DOWN	5
# define LFT_ARROW		123

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
typedef struct			s_img
{
	int	*ptr;
	int	bpp;
	int	size;
	int	endian;
}						t_img;
typedef struct			s_win
{
	void		*ptr;
	void		*img_ptr;
	t_point		p;
	int			mouse_pressed[8];
	int			key_pressed[280];
	t_list		*map;
	size_t		map_x;
	size_t		map_y;
}						t_win;
typedef struct			s_srv
{
	void		*mlx_ptr;
	int			win_opened;
}						t_srv;
extern volatile t_srv	g_srv;
/*
***************************************SRC**************************************
*/
void	get_map(char **argv, t_win *win);
void	plot_map(t_win *win);
int		line_clip(t_point *p_a, t_point *p_b, t_point incr, t_point diff);
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
**_________________________________/src/rescale.c_______________________________
*/
void	centr(t_win *win);
void	zoom_in(t_win *win);
void	zoom_out(t_win *win);
/*
**_________________________________/src/rotate.c_______________________________
*/
void	rotate_x(t_win *win, int direction);
void	rotate_y(t_win *win, int direction);
void	rotate_z(t_win *win, int direction);
/*
***************************************UTIL*************************************
*/
int		get_next_line(const int fd, char **line);
void	ft_assert(int i, char *s);
int		ft_abs(int n);
void	ft_swap(int *a, int *b);
int		get_nbr(char **s);

#endif
