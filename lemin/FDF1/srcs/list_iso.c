/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:48 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:54:50 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	iso_one(t_point *tmp)
{
	int x0;
	int y0;

	x0 = tmp->x;
	y0 = tmp->y;
	tmp->x = (float)(x0 - y0) * cos(0.523599);
	tmp->y = (float)(x0 + y0) * sin(0.523599) - (float)(tmp->z);
}

void	lst_iso(t_mlx *ptr)
{
	t_point *tmp;

	lst_x_sligt(ptr);
	tmp = ptr->map;
	while (tmp)
	{
		iso_one(tmp);
		tmp = tmp->next;
	}
}

void	lst_map_p(t_mlx *ptr)
{
	int		i;
	t_point	*tmp;
	t_connect *pointer;

	pointer = ptr->connects;
	tmp = ptr->map;
	i = 0;
	while (tmp)
	{
		// mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_croc_ptr, tmp->x, tmp->y);
		if (tmp->left)
			draw_line(*ptr, tmp, tmp->left);
		if (tmp->top)
			draw_line(*ptr, tmp, tmp->top);
		tmp = tmp->next;
		++i;
	}
	while (pointer)
	{
		draw_line(*ptr, pointer->t1, pointer->t2);
		pointer = pointer->next;
	}
	// mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_croc_ptr, 500, 500);
}

void	lst_x_sligt(t_mlx *ptr)
{
	float	x;
	float	y;
	float	z;
	int		i;
	t_point *tmp;

	tmp = ptr->map;
	i = 0;
	while (tmp)
	{
		tmp->x = tmp->x0;
		y = tmp->y0 - ptr->size_y * 40 / 2;
		tmp->y = (y) * cos(ptr->dx) + (tmp->z0) * sin(ptr->dx);
		tmp->z = -(y) * sin(ptr->dx) + (tmp->z0) * cos(ptr->dx);
		x = tmp->x - ptr->size_x * 40 / 2;
		z = tmp->z;
		tmp->x = x * cos(ptr->dy) + z * sin(ptr->dy);
		tmp->z = -x * sin(ptr->dy) + z * cos(ptr->dy);
		x = tmp->x;
		y = tmp->y;
		tmp->x = x * cos(ptr->dz) - y * sin(ptr->dz);
		tmp->y = x * sin(ptr->dz) + y * cos(ptr->dz);
		tmp = tmp->next;
	}
}
