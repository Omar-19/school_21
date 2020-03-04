/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:30:28 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/30 16:33:29 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int		my_sqrt(int a)
{
	int i;

	if (a == 0)
		return (0);
	i = 1;
	while (i * i < a)
		i++;
	return (i);
}

void	height(char *str, t_tetrem *tetre)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (str[i + 0] == '#' || str[i + 1] == '#' ||
		str[i + 2] == '#' || str[i + 3] == '#')
			tetre->height++;
		i += 5;
	}
}

void	width(char *str, t_tetrem *tetre)
{
	int i;

	i = -1;
	while (++i < 4)
		if (str[i + 0] == '#' || str[i + 5] == '#' ||
		str[i + 10] == '#' || str[i + 15] == '#')
			tetre->width++;
}

void	revers(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (i < 20)
	{
		c = str[3 + i];
		str[3 + i] = str[0 + i];
		str[0 + i] = c;
		c = str[1 + i];
		str[1 + i] = str[2 + i];
		str[2 + i] = c;
		i += 5;
	}
}
