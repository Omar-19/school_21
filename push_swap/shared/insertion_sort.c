#include "../include/header_ps.h"

void	stack_numbering(t_lst *head)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

void	zeroing(t_lst *a, t_lst *b, t_insert *tmp)
{
	tmp->len_a = stack_len(a);
	tmp->len_b = stack_len(b);;
	tmp->n_down = 0;
	tmp->n_ra = 0;
	tmp->n_rb = 0;
	tmp->n_rr = 0;
	tmp->n_rra = 0;
	tmp->n_rrb = 0;
	tmp->n_rrr = 0;
	tmp->n_up = 0;
	stack_numbering(a);
	stack_numbering(b);
}

void	position_in_a(t_lst *b, t_insert *tmp, t_lst *ptr)
{
	t_lst *ptr_next;

	ptr_next = ptr->next;
	while (ptr_next)
	{
		if (ptr_next && ((ptr->num > b->num && b->num > ptr_next->num)
			|| (ptr_next->num > b->num && b->num > ptr->num)))
		{
			tmp->num_in_a = ptr_next->pos;
			return ;
		}
		ptr = ptr->next;
		ptr_next = ptr->next;
	}
	tmp->num_in_a = 0;
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	_rr_(int *a1, int *a2, int *res)
{
	if (*a1 > *a2)
	{
		*res = *a2;
		*a1 -= *a2;
		*a2 = 0;
	}
	else
	{
		*res = *a1;
		*a2 -= *a1;
		*a1 = 0;
	}
}

void	min_step(t_lst *a, t_lst *b, t_insert *tmp)
{
	t_lst	*ptr;

	while (b)
	{
		ptr = a;
		tmp->n_rb = b->pos;
		tmp->n_rrb = tmp->len_b - b->pos;
		position_in_a(b, tmp, ptr);
		printf("in A: %d\n", tmp->num_in_a);
		tmp->n_ra = tmp->num_in_a;
		(tmp->num_in_a) ? (tmp->n_rra = tmp->len_a - tmp->num_in_a) : (tmp->n_rra = 0);
		tmp->n_up = tmp->n_ra + tmp->n_rrb;
		tmp->n_down = tmp->n_rra + tmp->n_rb;
		_rr_(&(tmp->n_ra), &(tmp->n_rb), &(tmp->n_rr));
		_rr_(&(tmp->n_rra), &(tmp->n_rrb), &(tmp->n_rrr));
		//tmp->n_up = tmp->n_ra + tmp->n_rb + tmp->n_rr;
		//tmp->n_down = tmp->n_rra + tmp->n_rrb + tmp->n_rrr;
		if (b->pos == 0 || tmp->min > max(tmp->n_up, tmp->n_down))
		{
			tmp->min = max(tmp->n_up, tmp->n_down);
			tmp->pos_b = b->pos;
		}
		printf("POSITION B = %d\n", b->pos);
		printf("len_a = %d   len_b = %d\n", tmp->len_a, tmp->len_b);
		printf("n_ra = %d   n_rb = %d   n_rr = %d\n", tmp->n_ra, tmp->n_rb, tmp->n_rr);
		printf("n_rra = %d   n_rrb = %d   n_rrr = %d\n", tmp->n_rra, tmp->n_rrb, tmp->n_rrr);
		printf("UP = %d   DOWN = %d\n-------------------\n", tmp->n_up, tmp->n_down);
		b = b->next;
	}
	printf("MIN = %d    POS_MIN = %d\n", tmp->min, tmp->pos_min);
}

void	insertion_sort(t_lst **a, t_lst **b, t_insert tmp)
{
	t_lst *c;

	zeroing(*a, *b, &tmp);
	printf("-----A-----\n");
	c = *a;
	while (c)
	{
		printf("%d ||| %lld\n", c->pos, c->num);
		c = c->next;
	}
	printf("-----------\n");
	c = *b;
	printf("-----B-----\n");
	while (c)
	{
		printf("%d ||| %lld\n", c->pos, c->num);
		c = c->next;
	}
	printf("-----------\n");
	// while (*b)
	// {
		zeroing(*a, *b, &tmp);
		min_step(*a, *b, &tmp);
		
	// }
}