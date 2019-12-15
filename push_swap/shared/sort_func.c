/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:25:35 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:25:37 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	rr_(int *a1, int *a2, int *res)
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

void	do_rarrb(t_lst *a, t_lst *b, t_insert tmp)
{
	while (tmp.n_ra--)
		ra(a, 1);
	while (tmp.n_rrb--)
		rrb(b, 1);
}

void	do_rrarb(t_lst *a, t_lst *b, t_insert tmp)
{
	while (tmp.n_rra--)
		rra(a, 1);
	while (tmp.n_rb--)
		rb(b, 1);
}

void	do_rabr(t_lst *a, t_lst *b, t_insert tmp)
{
	while (tmp.n_rr--)
		rr(a, b, 1);
	while (tmp.n_ra--)
		ra(a, 1);
	while (tmp.n_rb--)
		rb(b, 1);
}

void	do_rrabr(t_lst *a, t_lst *b, t_insert tmp)
{
	while (tmp.n_rrr--)
		rrr(a, b, 1);
	while (tmp.n_rra--)
		rra(a, 1);
	while (tmp.n_rrb--)
		rrb(b, 1);
}
