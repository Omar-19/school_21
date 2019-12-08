#include "../include/header_ps.h"

t_lst	*create_one_elem(void)
{
	t_lst *tmp;

	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	return (tmp);
}

void	sa(t_lst *a, int i)
{
	t_lst			*el;
	long long int	h;

	if (!a)
		return ;
	el = a->next;
	if (!a)
		return ;
	h = el->num;
	el->num = a->num;
	a->num = h;
	(i) ? (write(1, "sa\n", 3)) : 0;
}

void	sb(t_lst *b, int i)
{
	sa(b, 0);
	(i) ? (write(1, "sb\n", 3)) : 0;
}

void	ss(t_lst *a, t_lst *b, int i)
{
	sa(a, 0);
	sb(b, 0);
	(i) ? (write(1, "ss\n", 3)) : 0;
}

// проверить:
void	pa(t_lst **a, t_lst **b, int i)
{
	t_lst *head;

	if(!(*b))
		return ;
	if (!(head = create_one_elem()))
		return ;
	head->num = (*b)->num;
	head->next = (*a);
	(*a) = head;
	head = (*b)->next;
	// printf("head->num = %lld\n", head->num);
	free(*b);
	(*b) = head;
	(i) ? (write(1, "pa\n", 3)) : 0;
	// return (*b);
}

void	pb(t_lst **a, t_lst **b, int i)
{
	(i) ? (write(1, "pb\n", 3)) : 0;
	pa(b, a, 0);
	// return (c);
}

void	ra(t_lst *a, int i)
{
	long long int	el;
	t_lst			*tmp;

	el = a->num;
	tmp = a->next;
	while (tmp)
	{
		a->num = tmp->num;
		a = a->next;
		tmp = tmp->next;
	}
	a->num = el;
	(i) ? (write(1, "ra\n", 3)) : 0;
}

void	rb(t_lst *b, int i)
{
	ra(b, 0);
	(i) ? (write(1, "rb\n", 3)) : 0;
}

void	rr(t_lst *a, t_lst *b, int i)
{
	ra(a, 0);
	rb(b, 0);
	(i) ? (write(1, "rr\n", 3)) : 0;
}

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