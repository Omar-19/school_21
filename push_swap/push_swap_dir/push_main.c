/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:13:54 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:13:55 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

int	main(int ac, char **av)
{
	t_lst		*a;
	t_lst		*b;
	t_lst		*c;
	t_insert	tmp;
	int			f;

	a = NULL;
	b = NULL;
	tmp.len_a = 0;
	f = 0;
	if (ac == 1)
		return (0);
	if (!is_av_valid(ac, av))
		ft_error(NULL, NULL);
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	check_valid_elems(a);
	is_sort(&a, &b);
	c = a;
	insertion_sort(&a, &b, tmp);
	ft_clear_stack(a);
	ft_clear_stack(b);
	return (0);
}
