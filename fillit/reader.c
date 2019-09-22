/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simbo <simbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:59:10 by rthai             #+#    #+#             */
/*   Updated: 2019/09/22 01:29:15 by simbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	print_error()
{
	// ft_putstr("error\n");
	exit(1);
}

int			my_sqrt(int a)
{
	int i;
	
	i = 1;
	while (i * i < a)
		i++;
	return (i);
}

void		height(char *str, t_tetrem *tetre)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i + 0] == '#' || str[i + 1] == '#' ||
		str[i + 2] == '#' || str[i + 3] == '#')
			tetre->height++;
		i += 5;
	}
}

void		width(char *str, t_tetrem *tetre)
{
	int i;

	i = -1;
	while (++i < 4)
		if (str[i + 0] == '#' || str[i + 5] == '#' ||
		str[i + 10] == '#' || str[i + 15] == '#')
			tetre->width++;
}

void	width_length(char *str, t_tetrem *tetrem)
{
	int i;

	tetrem->width = 0;
	tetrem->height = 0;
	width(str, tetrem);
	height(str, tetrem);
	// printf("%s\nhight = %d\n", str, tetrem->height);
	// printf("width = %d\n", tetrem->width);
	
}

void	check_tetr(uint64_t tetr)
{
	if (tetr ^ 9223512776490647552ULL &&
		tetr ^ 17293822569102704640ULL &&
		tetr ^ 6917740133873614848ULL &&
		tetr ^ 9223583144161050624ULL &&
		tetr ^ 13835163608398430208ULL &&
		tetr ^ 4611897126807404544ULL &&
		tetr ^ 16140971433240035328ULL &&
		tetr ^ 4611897125733662720ULL &&
		tetr ^ 4611932309032009728ULL &&
		tetr ^ 9223583145234792448ULL &&
		tetr ^ 13835269161514696704ULL &&
		tetr ^ 16141041801984212992ULL &&
		tetr ^ 13835128425100083200ULL &&
		tetr ^ 2306089299818315776ULL &&
		tetr ^ 4611756390392791040ULL &&
		tetr ^ 9223618327459397632ULL &&
		tetr ^ 13835198794918002688ULL &&
		tetr ^ 16140936248867946496ULL)
			print_error();
}

void	shift_tetr(t_tetrem *tetr)
{
	
	while (!(tetr->tetreminka & 61440
	&& tetr->tetreminka & 9223512776490647552ULL))
		tetr->tetreminka <<= 1;
}

void	revers(char *str)
{
	char c;
	int i;

	i = 0;
	// while (i < 4)
	// {
	// 	c = str[0 + i];
	// 	str[0 + i] = str[15 + i];
	// 	str[15 + i] = c;
	// 	c = str[5 + i];
	// 	str[5 + i] = str[10 + i];
	// 	str[10 + i] = c;
	// 	i++;
	// }
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
void	filling_tetr(char *str, t_tetrem *tetrem)
{

	int			shift_64;
	int			i;
	int			flag;
	int			number = 0;
	
	flag = 0;
	i = 19;
	shift_64 = 0;
	tetrem->tetreminka = 0;
	width_length(str, tetrem);
	revers(str);
	while (i >= 0)
	{
		if ((!((i + 1) % 5) && str[i] != '\n') ||
		(((i + 1) % 5) && (str[i] != '.' && str[i] != '#')))
			print_error();
		if (str[i] == '#' && (flag = 1))
		{
			tetrem->tetreminka = (tetrem->tetreminka << 1) + 1;
			number++;
		}
		if (str[i] == '.' && (flag == 1))
			tetrem->tetreminka = (tetrem->tetreminka << 1);
		if (number != 4 && !((i + 1) % 5))
			tetrem->tetreminka <<= 12;
		i--;
		// print_mem(&(tetrem->tetreminka));
		// printf("\n");
	}
	(tetrem + 1)->tetreminka = 0;
	// print_mem(&(tetrem->tetreminka));
	shift_tetr(tetrem);
	// printf("tetr ^ %llu &&\n", tetrem->tetreminka);
	// printf("%u\n", temp);
	// check_tetr(tetrem->tetreminka);
	// tetrem->tetreminka = (uint64_t)temp;
	// print_mem(&(tetrem->tetreminka));
	// printf("\n");
}

int		size(t_tetrem *tetrem)
{
	int	size;
	int	size_squr;

	size_squr = 0;
	size = 0;
	while (tetrem->tetreminka)
	{
		if (tetrem->height == tetrem->width)
			size_squr++;
		else
			size++;
		tetrem++;
	}
	
	size_squr *= 7;
	printf("size2 = %d", my_sqrt(size_squr + size * 4));
	return(my_sqrt(size_squr + size * 4));
}

int		reader_file(char *name, t_tetrem *tetrem, t_map *map)
{
	char	str[BUF_SIZE + 1];
	int		ret;
	int		fd;
	int		i;

	i = 0;
	if (!(fd = open(name, O_RDONLY)))
		print_error();
	while ((ret = read(fd, str, BUF_SIZE)))
	{
		str[ret] = 0;
		filling_tetr(str, tetrem + i);
		read(fd, str, 1);
		if (!ret && str[0] != '\n')
			print_error();
		i++;
	}
	map->size = size(tetrem);
	printf("size = %d\n",  map->size);
}
