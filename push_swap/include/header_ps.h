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

void		sa(t_lst *a, int i);
void		sb(t_lst *b, int i);
void		ss(t_lst *a, t_lst *b, int i);
void		pa(t_lst **a, t_lst **b, int i);
void		pb(t_lst **a, t_lst **b, int i);
void		ra(t_lst *a, int i);
void		rb(t_lst *b, int i);
void		rr(t_lst *a, t_lst *b, int i);
void		rra(t_lst *a, int i);
void		rrb(t_lst *b, int i);
void		rrr(t_lst *a, t_lst *b, int i);
void		ft_clear_stack(t_lst *a);
void		ft_error(t_lst *a, t_lst *b);
t_lst		*read_stack(char **av, int ac, t_lst *a);
t_lst		*read_str_stack(char *av, t_lst *a);
void		check_valid_elems(t_lst *a);
int			is_str_valid(char *av);
int			is_av_valid(int ac, char **av);
void		ft_sort_three(t_lst *a);
void		ft_min_sort(t_lst *a, int i);
void		ft_create_b(t_lst **a, t_lst **b, int n);
void		check(t_lst *a);
void		is_sort(t_lst **a, t_lst **b);
t_lst		*creat_el(char *av, t_lst *a);

#endif