# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 16:06:00 by fmallist          #+#    #+#              #
#    Updated: 2019/11/20 18:38:45 by lmittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = srcs/main.c \
	srcs/button_press.c srcs/get_next_line.c srcs/line_dr1.c srcs/line_drawing.c srcs/list_iso.c \
	srcs/m1.c srcs/map_create.c srcs/mapc1.c
OBJ = $(SRCS:.c=.o)
LIBDIR = libft/
LIBNAME = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

$(LIBNAME):
	@make -C $(LIBDIR)

$(NAME): $(LIBNAME) $(OBJ)
	gcc $(CFLAGS) -lmlx -lm -framework OpenGL -framework AppKit \
	$(OBJ) -L $(LIBDIR) -lft -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAVE BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAVE BEEN DELETED.

re: fclean all
