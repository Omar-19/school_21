/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_commands_part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:17:27 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:17:29 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	sa(t_lst *a, int i)
{
	t_lst			*el;
	long long int	h;

	if (!a || !a->next)
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

void	ra(t_lst *a, int i)
{
	long long int	el;
	t_lst			*tmp;

	if (!a || !a->next)
		return ;
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
