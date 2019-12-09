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

void	min_step(t_lst *a, t_lst *b, t_insert *tmp)
{
	t_lst	*ptr;

	while (b)
	{
		// len -- ???
		ptr = a;
		tmp->n_rb = b->pos;
		tmp->n_rrb = tmp->len_b - b->pos;
		position_in_a(b, tmp, ptr);
		tmp->n_ra = tmp->num_in_a;
		tmp->n_rra = tmp->len_b - tmp->num_in_a;
		if (tmp->n_ra > tmp->n_rb)
		{
			tmp->n_rr = tmp->n_rb;
			tmp->n_ra -= tmp->n_rb;
			tmp->n_rb = 0;
		}
		else
		{
			tmp->n_rr = tmp->n_ra;
			tmp->n_rb -= tmp->n_ra;
			tmp->n_ra = 0;
		}
		if (tmp->n_rra > tmp->n_rrb)
		{
			tmp->n_rrr = tmp->n_rrb;
			tmp->n_rra -= tmp->n_rrb;
			tmp->n_rrb = 0;
		}
		else
		{
			tmp->n_rrr = tmp->n_rra;
			tmp->n_rrb -= tmp->n_rra;
			tmp->n_rra = 0;
		}
		tmp->n_up = tmp->n_ra + tmp->n_rb + tmp->n_rr;
		tmp->n_down = tmp->n_rra + tmp->n_rrb + tmp->n_rrr;
		// изначально min нет
		if (tmp->min > max(tmp->n_up, tmp->n_down))
		{
			tmp->min = max(tmp->n_up, tmp->n_down);
			tmp->pos_b = b->pos;
		}
		b = b->next;
	}
}

void	insertion_sort(t_lst **a, t_lst **b, t_insert tmp)
{
	while (*b)
	{
		zeroing(*a, *b, &tmp);
		min_step(a, b, &tmp);
	}
}