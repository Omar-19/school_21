/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthai <rthai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:06:36 by rthai             #+#    #+#             */
/*   Updated: 2019/09/21 22:27:19 by rthai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#define BUF_SIZE 20
#define MAX_TETRAM 26
#define TRUE 1
#define FALSE 0
#define CHECK_PUSH(x, y) ((x & y) == 0) ? TRUE : FALSE
 
#include <stdint.h>

typedef struct	s_tetrem
{
	uint64_t	tetreminka;
	unsigned x : 4;
	unsigned y : 4; 
	unsigned height : 4;
	unsigned width : 4;
}				t_tetrem;

typedef struct	s_map
{
	uint16_t		map_array[16];
	unsigned char	size;
}				t_map;

int		reader_file(char *name, t_tetrem *tetrem, t_map *map);
void	algorithm(t_tetrem *tetrem, t_map *map);
void	print_map(uint16_t *array);
void	print_mem(uint16_t *a);



#endif