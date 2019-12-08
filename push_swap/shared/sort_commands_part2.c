#include "../include/header_ps.h"

void	rra(t_lst *a, int i)
{
	t_lst			*head;
	t_lst			*tmp;
	long long int	el;
	long long int	s;

	head = a;
	tmp = a->next;
	s = a->num;
	while (tmp)
	{
		el = tmp->num;
		tmp->num = s;
		s = el;
		tmp = tmp->next;
	}
	head->num = el;
	(i) ? (write(1, "rra\n", 4)) : 0;
}

void	rrb(t_lst *b, int i )
{
	rra(b, 0);
	(i) ? (write(1, "rrb\n", 4)) : 0;
}

void	rrr(t_lst *a, t_lst *b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	(i) ? (write(1, "rrr\n", 4)) : 0;
}
