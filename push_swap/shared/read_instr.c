/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:17:19 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/15 18:17:20 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void		do_inst(t_lst **a, t_lst **b, char *line)
{
	int i;

	i = 0;
	(!ft_strcmp("sa\0", line)) ? (sa(*a, 0)) : (++i);
	(!ft_strcmp("sb\0", line)) ? (sb(*b, 0)) : (++i);
	(!ft_strcmp("ss\0", line)) ? (ss(*a, *b, 0)) : (++i);
	(!ft_strcmp("pa\0", line)) ? (pa(a, b, 0)) : (++i);
	(!ft_strcmp("pb\0", line)) ? (pb(a, b, 0)) : (++i);
	(!ft_strcmp("ra\0", line)) ? (ra(*a, 0)) : (++i);
	(!ft_strcmp("rb\0", line)) ? (rb(*b, 0)) : (++i);
	(!ft_strcmp("rr\0", line)) ? (rr(*a, *b, 0)) : (++i);
	(!ft_strcmp("rra\0", line)) ? (rra(*a, 0)) : (++i);
	(!ft_strcmp("rrb\0", line)) ? (rrb(*b, 0)) : (++i);
	(!ft_strcmp("rrr\0", line)) ? (rrr(*a, *b, 0)) : (++i);
	if (i == 11)
	{
		free(line);
		ft_error(*a, *b);
	}
}

void		color_num(char *line, t_flag *fl)
{
	if (!ft_strcmp("sa\0", line))
		fl->color = 1;
	else if (!ft_strcmp("sb\0", line))
		fl->color = 2;
	else if (!ft_strcmp("ss\0", line))
		fl->color = 3;
	else if (!ft_strcmp("ra\0", line) || !ft_strcmp("rra\0", line))
		fl->color = 4;
	else if (!ft_strcmp("rb\0", line) || !ft_strcmp("rrb\0", line))
		fl->color = 5;
	else if (!ft_strcmp("pa\0", line) || !ft_strcmp("pb\0", line) ||
			!ft_strcmp("rr\0", line) || !ft_strcmp("rrr\0", line))
		fl->color = 6;
	else
		fl->color = 0;
}

void		read_inst(t_lst **a, t_lst **b, t_flag *fl)
{
	char	*line;
	int		z;

	line = NULL;
	while ((z = get_next_line(0, &line)))
	{
		do_inst(a, b, line);
		(fl->c) ? (color_num(line, fl)) : 0;
		(line) ? free(line) : 0;
		(fl->v || fl->c) ? (print_stack(*a, *b, *fl)) : 0;
	}
	(line) ? free(line) : 0;
}
