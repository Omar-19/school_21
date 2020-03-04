/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:29:49 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/30 16:31:40 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 20
# define MAX_TETRAM 26
# define TRUE 1
# define FALSE 0
# define CHECK_PUSH(x, y) ((x & y) == 0) ? TRUE : FALSE
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_tetrem
{
	uint64_t	tetreminka;
	char		x;
	char		y;
	char		height;
	char		width;
}				t_tetrem;

typedef struct	s_map
{
	uint16_t		array[16];
	char			size;
}				t_map;

void			reader_file(char *name, t_tetrem *tetrem, t_map *map);
void			algorithm(t_tetrem *tetrem, t_map *map);
void			revers(char *str);
void			print_error();
int				my_sqrt(int a);
void			height(char *str, t_tetrem *tetre);
void			width(char *str, t_tetrem *tetre);
void			revers(char *str);
int				size_map(t_tetrem *tetrem, t_map *map);
void			filling_tetr(char *str, t_tetrem *tetrem);
#endif
