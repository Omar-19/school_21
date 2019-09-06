# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyuko <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:39:18 by fyuko             #+#    #+#              #
#    Updated: 2019/09/06 14:21:28 by fyuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
all:$(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c ./srcs/*.c -I./headers/
	@ar rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f libft.a
re: fclean all

.PHONY: all fclean clean re
