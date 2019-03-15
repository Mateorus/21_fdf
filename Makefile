# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 11:47:14 by gstiedem          #+#    #+#              #
#    Updated: 2019/03/14 14:42:19 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=fdf
SRCDIR:=src
UTILDIR:=util
OBJDIR:=obj
INCLUDE:=include
SRC:=$(addprefix $(SRCDIR)/,\
	)
UTIL:=$(addprefix $(UTILDIR)/,\
	)
OBJ:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ:=$(OBJ) $(patsubst $(UTILDIR)/%.c, $(OBJDIR)/%.o, $(UTIL))
LIB:=
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LIB) -I$(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o: $(UTILDIR)/%.c
	$(CC) $(CFLAGS) $(LIB) -I$(INCLUDE) -c $< -o $@

$(OBJ): |$(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

db: $(SRC) $(UTIL)
	$(CC) $(CFLAGS) $^ $(LIB) -I$(INCLUDE) -o $(NAME) -g
