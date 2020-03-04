/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:30:14 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/30 16:33:07 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	push_tetreminka(char *map_str, t_tetrem *tetrem, t_map *map, int id)
{
	int			i;
	int			j;
	int			j_str;
	uint16_t	*ptr;

	ptr = (uint16_t*)(&(tetrem->tetreminka));
	i = 0;
	while (i < 4)
	{
		j = 15;
		j_str = tetrem->x;
		while (j > 11)
		{
			if ((ptr[i] >> j) & 1)
				map_str[(map->size + 1) * tetrem->y + j_str] = id + 'A';
			j--;
			j_str++;
		}
		tetrem->y++;
		i++;
	}
}

void	print_map_str(t_tetrem *tetrem, t_map *map)
{
	char	*map_str;
	int		i;
	int		size;

	size = map->size * (1 + map->size);
	i = 0;
	map_str = (char*)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		if (i && !((i + 1) % (map->size + 1)))
			map_str[i] = '\n';
		else
			map_str[i] = '.';
		i++;
	}
	map_str[size] = 0;
	i = 0;
	while (tetrem->tetreminka)
	{
		push_tetreminka(map_str, tetrem, map, i);
		tetrem++;
		i++;
	}
	ft_putstr(map_str);
}

void	reader_file(char *name, t_tetrem *tetrem, t_map *map)
{
	char	str[BUF_SIZE + 1];
	int		ret;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		print_error();
	while ((ret = read(fd, str, BUF_SIZE - 1)))
	{
		if (i > 25)
			print_error();
		str[ret] = 0;
		filling_tetr(str, tetrem + i);
		ret = read(fd, str, 2);
		str[ret] = 0;
		if (ret != 1 && str[0] != '\n' && str[1] != '\n')
			print_error();
		if (ret == 1 && (str[0] != '\n' || str[1] == '\n'))
			print_error();
		i++;
	}
	if (str[1] != 0 || str[0] != '\n')
		print_error();
	map->size = my_sqrt(4 * i);
}

int		main(int argc, char **argv)
{
	t_tetrem	array_tetr[MAX_TETRAM + 1];
	t_map		map;

	if (argc != 2)
	{
		ft_putstr("usage: filling \"name_file_with_map\"\n");
		exit(1);
	}
	reader_file(argv[1], array_tetr, &map);
	algorithm(array_tetr, &map);
	print_map_str(array_tetr, &map);
}
