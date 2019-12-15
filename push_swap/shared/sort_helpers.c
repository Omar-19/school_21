/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:27:15 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:27:17 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	position_in_a(t_lst *b, t_insert *tmp, t_lst *ptr)
{
	t_lst *ptr_next;

	ptr_next = ptr->next;
	while (ptr_next)
	{
		if ((ptr->num < b->num && b->num < ptr_next->num) ||
			(ptr->num < b->num && b->num > ptr_next->num &&
			ptr->num > ptr_next->num) || (ptr->num > b->num &&
			b->num < ptr_next->num && ptr->num > ptr_next->num))
		{
			tmp->num_in_a = ptr_next->pos;
			return ;
		}
		ptr = ptr->next;
		ptr_next = ptr->next;
	}
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
		rr_(&(tmp->n_ra), &(tmp->n_rb), &(tmp->n_rr));
		rr_(&(tmp->n_rra), &(tmp->n_rrb), &(tmp->n_rrr));
		res.rabr = tmp->n_ra + tmp->n_rb + tmp->n_rr;
		res.rrabr = tmp->n_rra + tmp->n_rrb + tmp->n_rrr;
		if (b->pos == 0 || tmp->min > min(res))
		{
			tmp->min = min(res);
			tmp->pos_min = b->pos;
		}
		b = b->next;
	}
}
