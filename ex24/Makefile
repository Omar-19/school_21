# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyuko <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 16:32:44 by fyuko             #+#    #+#              #
#    Updated: 2019/09/03 16:37:56 by fyuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
ONAME = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
CFLAG = -Wall -Wextra -Werror -c
CC = gcc


all:
		$(CC) $(CFLAG) $(CNAME) -I./includes
		ar rc libft.a $(ONAME)
clean:
		/bin/rm -f $(OFILE)
fclean:
		/bin/rm -f libft.a
re:
		fclean all
.PHONY: all fclean clean re
