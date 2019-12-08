#include "../include/header_ps.h"

void		ft_clear_stack(t_lst *a)
{
	t_lst *ptr;

	while (a)
	{
		ptr = a->next;
		free(a);
		a = ptr;
	}
}

void	ft_error(t_lst *a, t_lst *b)
{
	// (a) ? (ft_clear_stack(a)) : 0;
	(b) ? (ft_clear_stack(b)) : 0;
	write(1, "Error\n", 6);
	exit(0);
}

t_lst	*read_stack(char **av, int ac, t_lst *a)
{
	t_lst	*head;
	t_lst	*tmp;
	size_t	i;

	i = 1;
	head = read_str_stack(av[i++], a);
	tmp = head;
	while(i < ac)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = read_str_stack(av[i++], a);
	}
	return (head);
}

t_lst	*read_str_stack(char *av, t_lst *a)
{
	t_lst	*head;
	size_t	i;
	char	*s;
	t_lst	*tmp;

	i = 1;
	if (!(s = ft_strchr(av, ' ')))
	{
		(!(head = creat_el(av, a))) ? ft_error(head, NULL) : 0;
		return(head);
	}
	(!(head = creat_el(av, a))) ? ft_error(head, NULL) : 0;
	tmp = head;
	av = s + 1;
	s = ft_strchr(av, ' ');
	while (s)
	{
		(!(tmp->next = creat_el(av, a))) ? ft_error(head, NULL) : 0;
		av = s + 1;
		s = ft_strchr(av, ' ');
		tmp = tmp->next;
	}
	tmp->next = creat_el(av, a);
	return (head);
}

void	check_valid_elems(t_lst *a)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	(!a) ? (ft_error(a, NULL)) : 0;
	while (a->next)
	{
		a->pos = i++;
		// (a->num > 2147483647 || a->num < -2147483648) ? (ft_error(a, NULL)) : 0; --- поправить проверку
		tmp = a->next;
		while (tmp)
		{
			(a->num == tmp->num) ? (ft_error(a, NULL)) : 0;
			tmp = tmp->next;
		}
		a = a->next;
	}
	a->pos = i;
}


int	is_str_valid(char *av)
{
	int i;

	i = 0;
	while(av[i] != '\0')
	{
		if (av[i] == '-')
			++i;
		if (av[i] > '9' || av[i] < '0')
			return (0);
		while(av[i] <= '9' && av[i] >= '0')
			++i;
		if (av[i] == ' ')
			++i;
	}
	return (1);
}

int	is_av_valid(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!is_str_valid(av[i]))
			return (0);
		++i;
	}
	return (1);
}

void	ft_sort_three(t_lst *a)
{
	t_lst *b;

	if (a->num < a->next->num && a->num > a->next->next->num)
	{
		rra(a, 1);
	}
	else if (a->num > a->next->next->num && a->next->num < a->next->next->num)
		ra(a, 1);
	else
	{
		sa(a, 1);
		if (a->num < a->next->num && a->num > a->next->next->num)
			rra(a, 1);
		else if (a->num > a->next->next->num && a->next->num < a->next->next->num)
			ra(a, 1);
		else
			return ;
	}
}

void	ft_min_sort(t_lst *a, int i)
{
	if (i == 0)
		exit(0);
	else if (i == 1)
		sa(a, 1);
	else
		ft_sort_three(a);
}

void	ft_create_b(t_lst **a, t_lst **b, int n)
{
	while (n-- >= 3)
		pb(a, b, 1);
	ft_sort_three(*a);
}

void	check(t_lst *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return ;
		a = a->next;
	}
	exit (0);
}

void	is_sort(t_lst **a, t_lst **b)
{
	t_lst	*ptr;
	t_lst	*head;

	head = *a;
	ptr = (*a)->next;
	check(*a);
	if (!ptr)
	{
		ft_clear_stack((*a));
		exit (0);
	}
	while (ptr->next)
		ptr = ptr->next;
	// printf("pos = %d\n", ptr->pos);
	(ptr->pos < 3) ? (ft_min_sort(head, ptr->pos)) : (ft_create_b(a, b, ptr->pos));
}

int main(int ac, char **av)
{
	t_lst   *a;
	t_lst   *b;
	t_lst   *c;
	int		f;

	a = NULL;
	b = NULL;
	f = 0;
	if (ac == 1 || !is_av_valid(ac, av))
	{
		ft_error(NULL, NULL);
        return (0);
	}
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	// printf("\n");
	check_valid_elems(a);
	is_sort(&a, &b);
	c = a;
	printf("-----A-----\n");
	while (c)
	{
		printf("num = %lld\n", c->num);
		c = c->next;
	}
	printf("-----------\n");
	c = b;
	printf("-----B-----\n");
	while (c)
	{
		printf("num = %lld\n", c->num);
		c = c->next;
	}
	printf("-----------\n");
	// b = a;
	// while (b)
	// {
	// 	printf("%lld ", b->num);
	// 	b = b->next;
	// }
	// printf("\n");
	return (0);
}