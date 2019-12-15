/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:06:06 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:06:09 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void		check_is_sort(t_lst *a, t_lst *b)
{
	if (a && check(a) && !b)
	{
		ft_clear_stack(a);
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		ft_clear_stack(a);
		ft_clear_stack(b);
		write(1, "KO\n", 3);
		exit(0);
	}
}

void		flags_zero(t_flag *fl)
{
	fl->c = 0;
	fl->f = 0;
	fl->v = 0;
	fl->color = 0;
}

int			flag_parsing(int *ac, char **av, t_flag *fl)
{
	int i;

	i = 0;
	if (!ft_strcmp("-v\0", av[1]) || (*ac > 2 && (!ft_strcmp("-v\0", av[2])))
		|| (*ac > 3 && (!ft_strcmp("-v\0", av[3]))))
		fl->v = 1;
	if (!ft_strcmp("-c\0", av[1]) || (*ac > 2 && (!ft_strcmp("-c\0", av[2])))
		|| (*ac > 3 && (!ft_strcmp("-c\0", av[3]))))
		fl->c = 1;
	if (!ft_strcmp("-f\0", av[1]) || (*ac > 2 && (!ft_strcmp("-f\0", av[2])))
		|| (*ac > 3 && (!ft_strcmp("-f\0", av[3]))))
		fl->f = 1;
	*ac -= fl->v + fl->c + fl->f;
	return (fl->v + fl->c + fl->f);
}

int			main(int ac, char **av)
{
	t_lst		*a;
	t_lst		*b;
	t_flag		fl;

	a = NULL;
	b = NULL;
	flags_zero(&fl);
	if (ac == 1)
		return (0);
	av += flag_parsing(&ac, av, &fl);
	if (!is_av_valid(ac, av))
		ft_error(NULL, NULL);
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	check_valid_elems(a);
	read_inst(&a, &b, &fl);
	check_is_sort(a, b);
	return (0);
}
