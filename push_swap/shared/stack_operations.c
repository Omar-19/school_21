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

int		stack_len(t_lst *head)
{
	int num;

	num = 0;
	while (head)
	{
		++num;
		head = head->next;
	}
	return (num);
}

void	ft_error(t_lst *a, t_lst *b)
{
	(a) ? (ft_clear_stack(a)) : 0;
	(b) ? (ft_clear_stack(b)) : 0;
	write(2, "Error\n", 6);
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
	while(i < (size_t)ac)
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
	// printf("S\n");
	if (!(s = ft_strchr(av, ' ')))
	{
		// printf("S\n");
		(!(head = creat_el(av, a))) ? ft_error(head, NULL) : 0;
		return(head);
		// printf("S\n");
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
