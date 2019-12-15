/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:08:19 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:08:26 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PS_H
# define HEADER_PS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/includes/header.h"
# include "../libft/libft/libft.h"
# define BUFF_SIZE 2
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

typedef struct		s_flag
{
	int	c;
	int v;
	int f;
	int color;
}					t_flag;

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

void				print_elem_a(int i, t_flag fl, t_lst **lst_a);
void				print_elem_b(int i, t_flag fl, t_lst **lst_b);
void				print_stack(t_lst *lst_a, t_lst *lst_b, t_flag fl);
void				rr_(int *a1, int *a2, int *res);
void				do_rarrb(t_lst *a, t_lst *b, t_insert tmp);
void				do_rrarb(t_lst *a, t_lst *b, t_insert tmp);
void				do_rabr(t_lst *a, t_lst *b, t_insert tmp);
void				do_rrabr(t_lst *a, t_lst *b, t_insert tmp);
void				stack_numbering(t_lst *head);
void				count_n_oper(t_lst *a, t_lst *b, t_insert *tmp, t_res *res);
void				sa(t_lst *a, int i);
void				sb(t_lst *b, int i);
void				ss(t_lst *a, t_lst *b, int i);
void				pa(t_lst **a, t_lst **b, int i);
void				pb(t_lst **a, t_lst **b, int i);
void				ra(t_lst *a, int i);
void				rb(t_lst *b, int i);
void				rr(t_lst *a, t_lst *b, int i);
void				rra(t_lst *a, int i);
void				rrb(t_lst *b, int i);
void				rrr(t_lst *a, t_lst *b, int i);
void				ft_clear_stack(t_lst *a);
void				ft_error(t_lst *a, t_lst *b);
int					get_next_line(const int fd, char **line);
t_lst				*read_stack(char **av, int ac, t_lst *a);
t_lst				*read_str_stack(char *av, t_lst *a);
void				check_valid_elems(t_lst *a);
int					is_str_valid(char *av);
int					is_av_valid(int ac, char **av);
void				ft_sort_three(t_lst *a);
void				ft_min_sort(t_lst *a, int i);
void				ft_create_b(t_lst **a, t_lst **b, int n);
int					check(t_lst *a);
int					stack_len(t_lst *head);
void				is_sort(t_lst **a, t_lst **b);
t_lst				*creat_el(char *av, t_lst *a);
void				zeroing(t_lst *a, t_lst *b, t_insert *tmp);
void				min_step(t_lst *a, t_lst *b, t_insert *tmp);
void				position_in_a(t_lst *b, t_insert *tmp, t_lst *ptr);
void				insertion_sort(t_lst **a, t_lst **b, t_insert tmp);
int					min(t_res res);
void				do_inst(t_lst **a, t_lst **b, char *line);
void				color_num(char *line, t_flag *fl);
void				read_inst(t_lst **a, t_lst **b, t_flag *fl);

#endif
