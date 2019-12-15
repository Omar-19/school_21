/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:16:37 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:16:38 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	zeroing(t_lst *a, t_lst *b, t_insert *tmp)
{
	tmp->len_a = stack_len(a);
	tmp->len_b = stack_len(b);
	tmp->n_ra = 0;
	tmp->n_rb = 0;
	tmp->n_rr = 0;
	tmp->n_rra = 0;
	tmp->n_rrb = 0;
	tmp->n_rrr = 0;
	stack_numbering(a);
	stack_numbering(b);
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
		do_rarrb(*a, *b, *tmp);
	else if (res.rrarb == tmp->min)
		do_rrarb(*a, *b, *tmp);
	else
	{
		rr_(&(tmp->n_ra), &(tmp->n_rb), &(tmp->n_rr));
		rr_(&(tmp->n_rra), &(tmp->n_rrb), &(tmp->n_rrr));
		if ((res.rabr = tmp->n_ra + tmp->n_rb + tmp->n_rr) == tmp->min)
			do_rabr(*a, *b, *tmp);
		else if ((res.rrabr = tmp->n_rra + tmp->n_rrb + tmp->n_rrr) == tmp->min)
			do_rrabr(*a, *b, *tmp);
		else
			ft_printf("");
	}
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
	t_lst	*ptr;
	int		n_ra;
	int		n_rra;

	n_rra = 0;
	ptr = *a;
	while (ptr->next)
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
}

void	insertion_sort(t_lst **a, t_lst **b, t_insert tmp)
{
	zeroing(*a, *b, &tmp);
	while (*b)
	{
		min_step(*a, *b, &tmp);
		insert(a, b, &tmp);
		zeroing(*a, *b, &tmp);
	}
	final_r(a);
}
