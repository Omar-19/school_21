/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:17:11 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:17:12 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	print_elem_a(int i, t_flag fl, t_lst **lst_a)
{
	ft_printf("|");
	(((i < 2) && ((fl.color == 1) || (fl.color == 3))) ||
	(fl.color == 4) || (fl.color == 6)) ?
	(ft_printf("%s", "\x1B[46m")) : 0;
	ft_printf(" %11lld ", (*lst_a)->num);
	*lst_a = (*lst_a)->next;
	(((i < 2) && ((fl.color == 1) || (fl.color == 3))) ||
	(fl.color == 4) || (fl.color == 6)) ?
	(ft_printf("%s", "\x1B[0m")) : 0;
}

void	print_elem_b(int i, t_flag fl, t_lst **lst_b)
{
	ft_printf("|");
	(((i < 2) && ((fl.color == 2) || (fl.color == 3))) ||
	(fl.color == 5) || (fl.color == 6)) ?
	(ft_printf("%s", "\x1B[46m")) : 0;
	ft_printf(" %11lld ", (*lst_b)->num);
	*lst_b = (*lst_b)->next;
	(((i < 2) && ((fl.color == 2) || (fl.color == 3))) ||
	(fl.color == 5) || (fl.color == 6)) ?
	(ft_printf("%s", "\x1B[0m")) : 0;
}

void	print_stack(t_lst *lst_a, t_lst *lst_b, t_flag fl)
{
	int i;

	i = 0;
	ft_printf(" ___________________________ \n");
	ft_printf("|%10s   |%10s   |\n", "stack A", "stack B");
	ft_printf("|_____________|_____________|\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
			print_elem_a(i, fl, &lst_a);
		else
			ft_printf("| %11c ", ' ');
		if (lst_b)
			print_elem_b(i, fl, &lst_b);
		else
			ft_printf("| %11c ", ' ');
		ft_printf("|\n");
		++i;
	}
	ft_printf("|_____________|_____________|\n\n");
}
