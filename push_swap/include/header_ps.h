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

typedef struct		s_res
{
	int rabr;
	int rrabr;
	int rarrb;
	int rrarb;
}					t_res;

typedef struct		s_insert
{
	int	len_a;
	int	len_b;
	int	n_ra;
	int	n_rb;
	int	n_rr;
	int	n_rra;
	int	n_rrb;
	int n_rrr;
	int num_in_a;
	int pos_b;
	int min;
	int pos_min;
}					t_insert;

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
int			check(t_lst *a);
int			stack_len(t_lst *head);
void		is_sort(t_lst **a, t_lst **b);
t_lst		*creat_el(char *av, t_lst *a);
void		zeroing(t_lst *a, t_lst *b, t_insert *tmp);
void		min_step(t_lst *a, t_lst *b, t_insert *tmp);
void		position_in_a(t_lst *b, t_insert *tmp, t_lst *ptr);
void		insertion_sort(t_lst **a, t_lst **b, t_insert tmp);
int			min(t_res res);

#endif