#include "../include/header_ps.h"

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
	if (!ft_strcmp("sa" ,line))
		sa(*a, 0);
	else if (!ft_strcmp("sb" ,line))
		sb(*b, 0);
	else if (!ft_strcmp("ss" ,line))
		ss(*a, *b, 0);
	else if (!ft_strcmp("pa" ,line))
		pa(a, b, 0);
	else if (!ft_strcmp("pb" ,line))
		pb(a, b, 0);
	else if (!ft_strcmp("ra" ,line))
		ra(*a, 0);
	else if (!ft_strcmp("rb" ,line))
		rb(*b, 0);
	else if (!ft_strcmp("rr" ,line))
		rr(*a, *b, 0);
	else if (!ft_strcmp("rra" ,line))
		rra(*a, 0);
	else if (!ft_strcmp("rrb" ,line))
		rrb(*b, 0);
	else if (!ft_strcmp("rrr" ,line))
		rrr(*a, *b, 0);
	else
		ft_error(*a, *b);
}

void		read_inst(t_lst **a, t_lst **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))//get_next_line(const int fd, char **line)
	{
		if (*line == '\0')
			break ;
		do_inst(a, b, line);
		// (hh->debug) ? plist_d(*a, *b, len_stack(*a), len_stack(*b)) : 0;
		(line) ? free(line) : 0;
	}
	(line) ? free(line) : 0;
	// if (check_sort(*a) && !(*b))
	// {
	// 	ft_clear_lst(*a);
	// 	write(1, "OK\n", 3);
	// }
	// else
	// {
	// 	ft_clear_lst(*a);
	// 	ft_clear_lst(*b);
	// 	write(1, "KO\n", 3);
	// }
}

int			main(int ac, char **av)
{
    t_lst		*a;
	t_lst		*b;;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!is_av_valid(ac, av))
		ft_error(NULL, NULL);
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	check_valid_elems(a);
	read_inst(&a, &b);
	t_lst *c;
	c = a;
	printf("------A------\n");
	while (c)
	{
		printf("%lld\n", c->num);
		c = c->next;
	}
	printf("-------------\n");
	printf("------B------\n");
	c = b;
	while (c)
	{
		printf("%lld\n", c->num);
		c = c->next;
	}
	printf("-------------\n");
	check_is_sort(a, b);
	return (0);
}