# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 11:47:14 by gstiedem          #+#    #+#              #
#    Updated: 2019/04/15 12:11:56 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=fdf
SRCDIR:=src
UTILDIR:=util
OBJDIR:=obj
INCLUDE:=-Iinclude -Iminilibx_macos -Ilibft
SRC:=$(addprefix $(SRCDIR)/,\
	main.c device_events.c system_events.c paint.c get_maps.c plot_map.c\
	line_clip.c morph.c)
UTIL:=$(addprefix $(UTILDIR)/,\
	get_next_line.c ft_assert.c ft_abs.c ft_swap.c get_nbr.c f_to_i_point.c\
	rev_list.c count_num.c)
OBJ:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ:=$(OBJ) $(patsubst $(UTILDIR)/%.c, $(OBJDIR)/%.o, $(UTIL))
LIB:=-lmlx -framework OpenGL -framework AppKit -lft
LIBPATH:=-L./minilibx_macos -L./libft
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	$(CC) $(LIB) $(LIBPATH) $^ -o $@

clean:
	make -C ./libft clean
	make -C ./minilibx_macos clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C ./libft fclean
	make -C ./minilibx_macos fclean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o: $(UTILDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ): |$(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

db: $(SRC) $(UTIL)
	$(CC) $(CFLAGS) $^ $(LIB) $(LIBPATH) $(INCLUDE) -o $(NAME) -g
