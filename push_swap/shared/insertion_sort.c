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
	tmp->n_ra = 0;
	tmp->n_rb = 0;
	tmp->n_rr = 0;
	tmp->n_rra = 0;
	tmp->n_rrb = 0;
	tmp->n_rrr = 0;
	stack_numbering(a);
	stack_numbering(b);
}

void	position_in_a(t_lst *b, t_insert *tmp, t_lst *ptr)
{
	t_lst *ptr_next;

	ptr_next = ptr->next;
	while (ptr_next)
	{
		// printf("num =  %lld  %lld  num_next = %lld\n", ptr->num, b->num, ptr_next->num);
		if ((ptr->num < b->num && b->num < ptr_next->num) ||
			(ptr->num < b->num && b->num > ptr_next->num && ptr->num > ptr_next->num) ||
			(ptr->num > b->num && b->num < ptr_next->num && ptr->num > ptr_next->num))
		{
			// printf("WOW!\n");
			tmp->num_in_a = ptr_next->pos;
			return ;
		}
		ptr = ptr->next;
		ptr_next = ptr->next;
	}
	// printf("0000000000000000000000000000\n");
	tmp->num_in_a = 0;
}

int		min(t_res res)
{
	int min;

	min = res.rabr;
	(min > res.rrabr) ? (min = res.rrabr) : 0;
	(min > res.rarrb) ? (min = res.rarrb) : 0;
	(min > res.rrarb) ? (min = res.rrarb) : 0;
	return (min);
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

void	count_n_oper(t_lst *a, t_lst *b, t_insert *tmp, t_res *res)
{
	tmp->n_rb = b->pos;
	tmp->n_rrb = tmp->len_b - b->pos;
	position_in_a(b, tmp, a);
	tmp->n_ra = tmp->num_in_a;
	if (tmp->num_in_a)
		tmp->n_rra = tmp->len_a - tmp->num_in_a;
	else
		tmp->n_rra = 0;
	res->rarrb = tmp->n_ra + tmp->n_rrb;
	res->rrarb = tmp->n_rra + tmp->n_rb;
}

void	min_step(t_lst *a, t_lst *b, t_insert *tmp)
{
	t_res	res;

	while (b)
	{
		count_n_oper(a, b, tmp, &res);
		_rr_(&(tmp->n_ra), &(tmp->n_rb), &(tmp->n_rr));
		_rr_(&(tmp->n_rra), &(tmp->n_rrb), &(tmp->n_rrr));
		res.rabr = tmp->n_ra + tmp->n_rb + tmp->n_rr;
		res.rrabr = tmp->n_rra + tmp->n_rrb + tmp->n_rrr;
		if (b->pos == 0 || tmp->min > min(res))
		{
			tmp->min = min(res);
			tmp->pos_min = b->pos;
			// printf("POS = %d   rabr = %d rrabr = %d rarrb = %d rrarb = %d\n", tmp->pos_b, res.rabr, res.rrabr, res.rarrb, res.rrarb);
		}
		b = b->next;
		// printf("rabr = %d rrabr = %d rarrb = %d rrarb = %d\n", res.rabr, res.rrabr, res.rarrb, res.rrarb);

	}
	// printf("%d %d %d %d", res.rabr, res.rarrb);
}

void	do_rarrb(t_lst *a, t_lst *b, t_res res, t_insert tmp)
{
	while (tmp.n_ra--)
		ra(a, 1);
	while (tmp.n_rrb--)
		rrb(b, 1);
}

void	do_rrarb(t_lst *a, t_lst *b, t_res res, t_insert tmp)
{
	while (tmp.n_rra--)
		rra(a, 1);
	while (tmp.n_rb--)
		rb(b, 1);
}

void	do_rabr(t_lst *a, t_lst *b, t_res res, t_insert tmp)
{
	while (tmp.n_rr--)
		rr(a, b, 1);
	while (tmp.n_ra--)
		ra(a, 1);
	while (tmp.n_rb--)
		rb(b, 1);
}

void	do_rrabr(t_lst *a, t_lst *b, t_res res, t_insert tmp)
{
	while (tmp.n_rrr--)
		rrr(a, b, 1);
	while (tmp.n_rra--)
		rra(a, 1);
	while (tmp.n_rrb--)
		rrb(b, 1);
}

void	insert(t_lst **a, t_lst **b, t_insert *tmp)
{
	t_res	res;
	t_lst	*c;

	c = *b;
	while (c->pos != tmp->pos_min)
		c = c->next;
	count_n_oper(*a, c, tmp, &res);
	if (res.rarrb == tmp->min)
		do_rarrb(*a, *b, res, *tmp);
	else if (res.rrarb == tmp->min)
		do_rrarb(*a, *b, res, *tmp);
	else
	{
		_rr_(&(tmp->n_ra), &(tmp->n_rb), &(tmp->n_rr));
		_rr_(&(tmp->n_rra), &(tmp->n_rrb), &(tmp->n_rrr));
		if ((res.rabr = tmp->n_ra + tmp->n_rb + tmp->n_rr) == tmp->min)
			do_rabr(*a, *b, res, *tmp);
		else if ((res.rrabr = tmp->n_rra + tmp->n_rrb + tmp->n_rrr) == tmp->min)
			do_rrabr(*a, *b, res, *tmp);
		else
			printf("----------------------((((-----------------\n");
	}
			// c = NULL;
	// printf("VVV-----A-----\n");
	// c = *a;
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("VVV-----------\n");
	// c = *b;
	// printf("VVV-----B-----\n");
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("VVV-----------\n");
	pa(a, b, 1);	
}

void	rotate_a(t_lst **a, int n_ra, int n_rra)
{
	if (n_ra > n_rra)
		while (n_rra--)
			rra(*a, 1);
	else
		while (n_ra--)
			ra(*a, 1);
}

void	final_r(t_lst **a)
{
	t_lst *ptr;
	int n_ra;
	int n_rra;

	n_rra = 0;
	ptr = *a;
	while(ptr->next)
	{
		if (ptr->num > ptr->next->num)
			n_ra = ptr->next->pos;
		ptr = ptr->next;
	}
	if (!n_ra)
		return ;
	else
		n_rra = stack_len(*a) - n_rra;
	rotate_a(a, n_ra, n_rra);
	// printf("ra = %d rra = %d\n", n_ra, n_rra);
}

void	insertion_sort(t_lst **a, t_lst **b, t_insert tmp)
{
	t_lst *c;

	zeroing(*a, *b, &tmp);
	// printf("-----A-----\n");
	// c = *a;
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
	// c = *b;
	// printf("-----B-----\n");
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
	// int i = 1;
	while (*b)
	{
		// printf("\n STEP %d\n", i++);
		min_step(*a, *b, &tmp);
		insert(a, b, &tmp);
		zeroing(*a, *b, &tmp);
		// printf("MIN = %d    POS_MIN = %d va = %d\n", tmp.min, tmp.pos_min, tmp.num_in_a);
		// printf("-----A-----\n");
		// c = *a;
		// while (c)
		// {
		// 	printf("%d ||| %lld\n", c->pos, c->num);
		// 	c = c->next;
		// }
		// printf("-----------\n");
		// c = *b;
		// printf("-----B-----\n");
		// while (c)
		// {
		// 	printf("%d ||| %lld\n", c->pos, c->num);
		// 	c = c->next;
		// }
		// printf("-----------\n\n");
	}
	// printf("-----A-----\n");
	// c = *a;
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
	final_r(a);
	// zeroing(*a, *b, &tmp);
	// min_step(*a, *b, &tmp);
	// insert(a, b, &tmp);
	// printf("MIN = %d    POS_MIN = %d va = %d\n", tmp.min, tmp.pos_min, tmp.num_in_a);

	printf("-----A-----\n");
	c = *a;
	while (c)
	{
		printf("%d ||| %lld\n", c->pos, c->num);
		c = c->next;
	}
	printf("-----------\n");
	// c = *b;
	// printf("-----B-----\n");
	// while (c)
	// {
	// 	printf("%d ||| %lld\n", c->pos, c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
}