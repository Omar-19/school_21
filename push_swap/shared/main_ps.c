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
	(a) ? (ft_clear_stack(a)) : 0;
	(b) ? (ft_clear_stack(b)) : 0;
	write(1, "Error\n", 6);
	exit(0);
}

t_lst	*read_stack(char **av, int ac)
{
	t_lst	*head;
	t_lst	*tmp;
	size_t	i;

	i = 1;
	head = read_str_stack(av[i++]);
	tmp = head;
	while(i < ac)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = read_str_stack(av[i++]);
	}
	return (head);
}

t_lst	*read_str_stack(char *av)
{
	t_lst	*head;
	size_t	i;
	char	*s;
	t_lst	*tmp;

	i = 1;
	if (!(s = ft_strchr(av, ' ')))
	{
		(!(head = creat_el(av))) ? ft_error(head, NULL) : 0;
		return(head);
	}
	(!(head = creat_el(av))) ? ft_error(head, NULL) : 0;
	tmp = head;
	av = s + 1;
	s = ft_strchr(av, ' ');
	while (s)
	{
		(!(tmp->next = creat_el(av))) ? ft_error(head, NULL) : 0;
		av = s + 1;
		s = ft_strchr(av, ' ');
		tmp = tmp->next;
	}
	tmp->next = creat_el(av);
	return (head);
}

void	check_valid_elems(t_lst *a)
{
	t_lst *tmp;

	(!a) ? (ft_error(a, NULL)) : 0;
	while (a->next)
	{
		// (a->num > 2147483647 || a->num < -2147483648) ? (ft_error(a, NULL)) : 0; --- поправить проверку
		tmp = a->next;
		while (tmp)
		{
			(a->num == tmp->num) ? (ft_error(a, NULL)) : 0;
			tmp = tmp->next;
		}
		a = a->next;
	}
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

int main(int ac, char **av)
{
	t_lst   *a;
	t_lst   *b;
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
		a = read_str_stack(av[1]);
	else
		a = read_stack(av, ac);
	b = a;
	while (b)
	{
		printf("num = %lld   pos = %d\n", b->num, b->pos);
		b = b->next;
	}
	printf("\n");
	check_valid_elems(a);
	// b = a;
	// while (b)
	// {
	// 	printf("%lld ", b->num);
	// 	b = b->next;
	// }
	// printf("\n");
	return (0);
}