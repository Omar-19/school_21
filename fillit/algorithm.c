/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simbo <simbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:53:57 by rthai             #+#    #+#             */
/*   Updated: 2019/09/22 01:11:48 by simbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

int		algorithm_rec(t_tetrem *tetrem, t_map *map)
{
	int		j;
	int		i;

	i = 0;
	if (tetrem->tetreminka == 0)
		return (1);
	while (i < map->size - tetrem->height)
	{
		j = 0;
		while (j < map->size - tetrem->width)
		{
			if (CHECK_PUSH(tetrem->tetreminka >> j, *(uint64_t*)(map->map_array + i)))
			{
				*(uint64_t*)(map->map_array + i) ^= tetrem->tetreminka >> j;
				// print_map(map->map_array);
				// printf("i = %dj = %d\n", i, j);
				if (algorithm_rec(tetrem + 1, map))
					return (1);
				*(uint64_t*)(map->map_array + i) ^= tetrem->tetreminka >> j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	algorithm(t_tetrem *tetrem, t_map *map)
{
	int a;

	while (map->size < 16)
	{
		// printf("lsol = %d\n", map->size);
		ft_bzero(map->map_array, sizeof(uint16_t) * 16);
		if((a = algorithm_rec(tetrem, map)))
			return ;
		// print_map(map->map_array);
		// printf("\n");
		map->size++;
	}
}