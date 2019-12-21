/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:55:05 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:55:07 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	help_map(int *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 1;
}

void	help_map1(t_point *tmp)
{
	tmp->x0 = 0;
	tmp->y0 = 0;
}

void	resize_map(t_mlx *ptr, int l)
{
	t_point	*tmp;
	int		i[3];

	help_map(i);
	tmp = ptr->map;
	ptr->size_line += l;
	if (ptr->size_line < 0)
	{
		ptr->size_line = 0;
		i[2] = 0;
	}
	while (tmp)
	{
		(i[0] % ptr->size_x == 0) ? (++i[1]) : 0;
		if (i[2])
		{
			tmp->x0 = tmp->x0 + l * (i[0] % ptr->size_x);
			tmp->y0 = tmp->y0 + l * i[1];
		}
		if (!i[2])
			help_map1(tmp);
		tmp = tmp->next;
		++i[0];
	}
}

void	del_map(t_point **map)
{
	t_point *tmp;
	t_point *next;

	tmp = *map;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*map = NULL;
}

t_connect *create_elem_lst_connect(void)
{
	t_connect *ptr;

	ptr = (t_connect *)malloc(sizeof(t_connect));
	ptr->next = NULL;
	return (ptr);
}

void	setting_point_links(t_mlx *ptr, int t1, int t2)
{
	int			i;
	t_connect	*tmp;
	t_point		*p;

	tmp = ptr->connects;
	while (tmp->next)
		tmp = tmp->next;
	i = 1;
	p = ptr->map;
	while(p)
	{
		if (i == t1)
			tmp->t1 = p;
		if (i == t2)
			tmp->t2 = p + t2;
		++i;
		p = p->next;
	}
}

void	create_elem_connect(t_mlx *ptr, int t1, int t2, int i)
{
	t_connect *tmp;

	tmp = NULL;
	if (i == 1)
		ptr->connects = create_elem_lst_connect();
	else
	{
		tmp = ptr->connects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_elem_lst_connect();
		tmp = tmp->next;
	}
	// t1++;
	// t2++;
	setting_point_links(ptr, t1, t2);
}

void	create_connect(int ac, char **av, t_mlx *ptr)
{
	int i;
	int t1;
	int t2;

	ptr->pix_m += 0;
	i = 1;
	while (--ac)
	{
		t1 = ft_atoi(av[i]);
		t2 = ft_atoi(ft_strchr(av[i], '-') + 1);
		create_elem_connect(ptr, t1, t2, i);
		++i;
	}
}

int		main(int argc, char **argv)
{
	t_mlx	ptr;
	t_file	file;
	t_strm	*head_s;
	t_strm	*tmp;
	int		i;

	ft_bzero((void *)(&ptr), sizeof(t_mlx));
	ptr.size_line = 60;
	// if (argc != 2)
	// 	return (0);
	ptr.color1 = RED;
	file.fd = open(argv[1], O_RDONLY);
	read_map(&ptr, &file, &head_s, &tmp);
	create_map(&ptr, &head_s, &tmp);
	ptr.img_ptr = NULL;
	ptr.img_bug_ptr = NULL;
	file.fd = open(argv[2], O_RDONLY);

	// тестовое задание вершин:
	t_point *p = ptr.map;
	i = 0;
	while(p)
	{
		if (i % 3 == 0)
			p->is_vertex = 1;
		else
			p->is_vertex = 0;
		p = p->next;
		++i;
	}
	argc += 0;
	create_connect(--argc, ++argv, &ptr);
	// while (ptr.connects)
	// {
	// 	printf("WOW!\n");
	// 	ptr.connects = ptr.connects->next;
	// }
	create_image(&ptr);
	return (0);
}
