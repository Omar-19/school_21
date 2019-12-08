#include "../include/header_ps.h"

t_lst	*create_one_elem(void)
{
	t_lst *tmp;

	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	return (tmp);
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

void	rr(t_lst *a, t_lst *b, int i)
{
	ra(a, 0);
	rb(b, 0);
	(i) ? (write(1, "rr\n", 3)) : 0;
}