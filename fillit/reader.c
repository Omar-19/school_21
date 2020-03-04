/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:30:02 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/30 16:30:04 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	width_length(char *str, t_tetrem *tetrem)
{
	tetrem->width = 0;
	tetrem->height = 0;
	width(str, tetrem);
	height(str, tetrem);
	revers(str);
}

void	check_tetr(uint64_t tetr)
{
	if (tetr ^ 9223512776490647552ULL &&
		tetr ^ 61440 &&
		tetr ^ 3221250048 &&
		tetr ^ 70371965435904 &&
		tetr ^ 1610661888 &&
		tetr ^ 140740709597184 &&
		tetr ^ 1073799168 &&
		tetr ^ 70371965419520 &&
		tetr ^ 3758112768 &&
		tetr ^ 140740709613568 &&
		tetr ^ 3221274624 &&
		tetr ^ 211108380049408 &&
		tetr ^ 2147540992 &&
		tetr ^ 70369817968640 &&
		tetr ^ 3758104576 &&
		tetr ^ 211107306291200 &&
		tetr ^ 3758129152 &&
		tetr ^ 140739635888128 &&
		tetr ^ 536928256)
		print_error();
}

void	shift_tetr(t_tetrem *tetr)
{
	while (!(tetr->tetreminka & 61440
	&& tetr->tetreminka & 9223512776490647552ULL))
		tetr->tetreminka <<= 1;
	check_tetr(tetr->tetreminka);
}

void	filling_tetr(char *str, t_tetrem *tetrem)
{
	int			i;
	int			flag;
	int			number;

	flag = 0;
	i = 19;
	number = 0;
	tetrem->tetreminka = 0;
	width_length(str, tetrem);
	while (--i >= 0)
	{
		if ((!((i + 1) % 5) && str[i] != '\n') ||
		(((i + 1) % 5) && (str[i] != '.' && str[i] != '#')))
			print_error();
		if (str[i] == '#' && (flag = 1) && (++number))
			tetrem->tetreminka = (tetrem->tetreminka << 1) + 1;
		if (str[i] == '.' && (flag == 1))
			tetrem->tetreminka = (tetrem->tetreminka << 1);
		if (number != 4 && !((i + 1) % 5))
			tetrem->tetreminka <<= 12;
	}
	if (tetrem->tetreminka == 0)
		print_error();
	(tetrem + 1)->tetreminka = 0;
	shift_tetr(tetrem);
}
