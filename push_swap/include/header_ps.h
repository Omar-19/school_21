#ifndef HEADER_PS_H
# define HEADER_PS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/includes/header.h"
# include "../libft/libft/libft.h"
# define BUFF_SIZE 7
# define ESC "\x1b"

typedef struct		s_lst
{
	struct s_lst	*next;
	long long int	num;
	int				pos;
}					t_lst;

typedef struct		s_str
{
	int				suml;
	// int				fa;
	// int				fb;
	// int				ta;
	// int				tb;
	// int				len_s;
	// int				max_div;
	// int				debug;
	// int				col;
	// int				f;
	// int				big;
	// int				max1;
	// int				um;
	// int				min_num1;
	// int				pos1;
}					t_str;

void		ft_clear_stack(t_lst *a);
void		ft_error(t_lst *a, t_lst *b);
t_lst		*read_stack(char **av, int ac, t_lst *a);
t_lst		*read_str_stack(char *av, t_lst *a);
t_lst		*creat_el(char *av, t_lst *a);

#endif