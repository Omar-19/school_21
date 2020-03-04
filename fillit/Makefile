DIR = libft/
NAME = fillit
LIB = libft.a
FILES =	algorithm.c \
		fillit.c \
		reader.c \
		help_function.c \

OBJ = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(DIR)
	gcc $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $(<) -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(DIR) fclean

re: fclean all

.PHONY: all clean fclean re