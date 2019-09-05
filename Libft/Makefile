# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyuko <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:39:18 by fyuko             #+#    #+#              #
#    Updated: 2019/09/05 20:44:08 by fyuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAG= -Wall -Wextra -Werror -c
OBJECT= ft_bzero.c ft_isdigit.c ft_memcmp.c	ft_strcat.c	ft_strdup.c	ft_strncpy.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_isalpha.c ft_memccpy.c ft_memmove.c	ft_strcmp.c	ft_strncat.c ft_strstr.c ft_isascii.c ft_memchr.c ft_memset.c ft_strcpy.c ft_strncmp.c ft_tolower.c
TARGET= libft.a
HEADER= -I./includes
OFILE= ft_bzero.o ft_isdigit.o ft_memcmp.o ft_strcat.o ft_strdup.o ft_strncpy.o ft_toupper.o ft_isalnum.o ft_isprint.o ft_memcpy.o ft_    strchr.o ft_strlen.o ft_strrchr.o ft_isalpha.o ft_memccpy.o ft_memmove.o ft_strcmp.o ft_strncat.o ft_strstr.o ft_isascii.o ft_memchr.o ft_memset.o ft_strcpy.o ft_strncmp.o ft_tolower.o
all:
	    $(CC) $(CFLAG) $(OBJECT) $(HEADER)
		    ar rc $(TARGET) $(OFILE)
clean:
	    /bin/rm -f $(OFILE)
fclean: clean
	    /bin/rm -f $(TARGET)
re: fclean all
	.PHONY: all fclean clean re
