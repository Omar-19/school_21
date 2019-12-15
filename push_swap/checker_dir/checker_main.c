#include "../include/header_ps.h"

// void	write_stack(t_lst *a, t_lst *b)
// {
// 	t_lst *c;
// 	c = a;
// 	printf("------A------\n");
// 	while (c)
// 	{
// 		printf("%lld\n", c->num);
// 		c = c->next;
// 	}
// 	printf("-------------\n");
// 	printf("------B------\n");
// 	c = b;
// 	while (c)
// 	{
// 		printf("%lld\n", c->num);
// 		c = c->next;
// 	}
// 	printf("-------------\n");
// }

void	check_is_sort(t_lst *a, t_lst *b)
{
	if (a && check(a) && !b)
	{
		ft_clear_stack(a);
		write(1, "OK\n", 3);
		exit (0);
	}
	else
	{
		ft_clear_stack(a);
		ft_clear_stack(b);
		write(1, "KO\n", 3);
		exit (0);
	}
}

void		do_inst(t_lst **a, t_lst **b, char *line)
{
	if (!ft_strcmp("sa\0" ,line))
		sa(*a, 0);
	else if (!ft_strcmp("sb\0", line))
		sb(*b, 0);
	else if (!ft_strcmp("ss\0", line))
		ss(*a, *b, 0);
	else if (!ft_strcmp("pa\0", line))
		pa(a, b, 0);
	else if (!ft_strcmp("pb\0", line))
		pb(a, b, 0);
	else if (!ft_strcmp("ra\0", line))
		ra(*a, 0);
	else if (!ft_strcmp("rb\0", line))
		rb(*b, 0);
	else if (!ft_strcmp("rr\0", line))
		rr(*a, *b, 0);
	else if (!ft_strcmp("rra\0", line))
		rra(*a, 0);
	else if (!ft_strcmp("rrb\0", line))
		rrb(*b, 0);
	else if (!ft_strcmp("rrr\0", line))
		rrr(*a, *b, 0);
	else
	{
		free(line);
		ft_error(*a, *b);
	}
}

void	print_stack(t_lst *lst_a, t_lst *lst_b)
{
	// t_lst *lst_a;
	// t_lst *lst_b;

	// lst_a = *a;
	// lst_b = *b;
	ft_printf(" ___________________________\n");
	ft_printf("|%10s   |%10s   |\n", "stack A", "stack B");
	ft_printf("|_____________|_____________|\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_printf("| %11lld ", lst_a->num);
			lst_a = lst_a->next;
		}
		else
			ft_printf("| %11c ", ' ');
		if (lst_b)
		{
			ft_printf("| %11lld ", lst_b->num);
			lst_b = lst_b->next;
		}
		else
			ft_printf("| %11c ", ' ');
		ft_printf("|\n");
	}
	ft_printf("|_____________|_____________|\n");//2 147 483 647
	// printf("%11s %11s\n", "stack A", "stack B");
}

void		read_inst(t_lst **a, t_lst **b, t_flag fl)
{
	char	*line;
	int		z;

	line = NULL;
	while ((z = get_next_line(0, &line)))
	{
		do_inst(a, b, line);
		(line) ? free(line) : 0;
		// (fl.v) ? (write_stack(*a, *b)) : 0;
		(fl.v) ? (print_stack(*a, *b)) : 0;
	}
	(line) ? free(line) : 0;
}

void		flags_zero(t_flag *fl)
{
	fl->c = 0;
	fl->f = 0;
	fl->v = 0;
}

int			main(int ac, char **av)
{
    t_lst		*a;
	t_lst		*b;
	t_flag		fl;

	a = NULL;
	b = NULL;
	flags_zero(&fl);
	if (ac == 1)
		return (0);
	if (!ft_strcmp("-v\0", av[1]))
	{
		fl.v = 1;
		++av;
		--ac;
	}
	if (!is_av_valid(ac, av))
		ft_error(NULL, NULL);
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	check_valid_elems(a);
	read_inst(&a, &b, fl);
	check_is_sort(a, b);
	return (0);
}