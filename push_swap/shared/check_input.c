/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:16:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:18:07 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	check_valid_elems(t_lst *a)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	(!a) ? (ft_error(a, NULL)) : 0;
	while (a->next)
	{
		a->pos = i++;
		tmp = a->next;
		while (tmp)
		{
			(a->num == tmp->num) ? (ft_error(a, NULL)) : 0;
			tmp = tmp->next;
		}
		a = a->next;
	}
	a->pos = i;
}

int		is_str_valid(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '-' || av[i] == '+')
			++i;
		if (av[i] > '9' || av[i] < '0')
			return (0);
		while (av[i] <= '9' && av[i] >= '0')
			++i;
		if (av[i] == ' ')
			++i;
	}
	return (1);
}

int		is_av_valid(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!is_str_valid(av[i]))
			return (0);
		++i;
	}
	return (1);
}

int		check(t_lst *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	is_sort(t_lst **a, t_lst **b)
{
	t_lst	*ptr;
	t_lst	*head;

	head = *a;
	ptr = (*a)->next;
	if (check(*a))
		exit(0);
	if (!ptr)
	{
		ft_clear_stack((*a));
		exit(0);
	}
	while (ptr->next)
		ptr = ptr->next;
	(ptr->pos < 3) ? (ft_min_sort(head, ptr->pos))
		: (ft_create_b(a, b, ptr->pos));
}
