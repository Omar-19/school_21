/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:59 by fyuko             #+#    #+#             */
/*   Updated: 2019/12/17 15:28:15 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	create_mlx_img(t_mlx *ptr)
{
	if (ptr->img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->pix_m_size), &(ptr->endian));
	lst_iso(ptr);
	if (abs(*(ptr->z_max)) > abs(*(ptr->z_min)))
		ptr->g = (float)255 / (float)(abs(*(ptr->z_max)) * ptr->size_line);
	else
	{
		if (abs(*(ptr->z_min)) == 0)
			ptr->g = 0;
		else
			ptr->g = (float)255 / (float)(abs(*(ptr->z_min)) * ptr->size_line);
	}
	lst_map_p(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	int		i;
	t_point	*tmp;

	tmp = ptr->map;
	i = 0;
	while (tmp)
	{
		if (tmp->is_vertex)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_croc_ptr,
				tmp->x + WIDTH / 2 - 20, tmp->y + HEIGHT / 2 - 25);
		tmp = tmp->next;
	}
}


// void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height)
// {
//   int	fd;
//   int	size;
//   char	*ptr;
//   t_img	*img;

//   fd = -1;
//   if ((fd = open(file,O_RDONLY))==-1 || (size = lseek(fd,0,SEEK_END))==-1 ||
//       (ptr = mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE,fd,0))==
//       (void *)MAP_FAILED)
//     {
//       if (fd>=0)
// 	close(fd);
//       return ((void *)0);
//     }
//   mlx_int_file_get_rid_comment(ptr, size);
//   if (img = mlx_int_parse_xpm(xvar,ptr,size,mlx_int_get_line))
//     {
//       *width = img->width;
//       *height = img->height;
//     }
//   munmap(ptr,size);
//   close(fd);
//   return (img);
// }

// void	*mlx_xpm_to_image(t_xvar *xvar,char **xpm_data,int *width,int *height)
// {
//   t_img	*img;

//   if (img = mlx_int_parse_xpm(xvar,xpm_data,0,mlx_int_static_line))
//     {
//       *width = img->width;
//       *height = img->height;
//     }
//   return (img);
// }


int		create_image(t_mlx *ptr)
{
	ptr->dx = 0;
	ptr->dy = 0;
	ptr->dz = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF project");
	int a = 100;
	int b = 100;
	ptr->img_bug_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "./bug.xpm", &a, &b);
	ptr->img_croc_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "./lst.xpm", &a, &b);
	create_mlx_img(ptr);
	mlx_hook(ptr->win_ptr, 2, 0, key_press, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}
