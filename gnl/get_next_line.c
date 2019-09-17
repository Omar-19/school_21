/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:54:01 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/17 12:17:26 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_check_list(t_list **head, const int fd)
{
	t_list *ptr;
	char s[BUFF_SIZE + 1];

	ft_bzero(s, BUFF_SIZE + 1);
	ptr = *head;
	if (!ptr)
	{
		if ((ptr = ft_lstnew(s, BUFF_SIZE + 1)) == NULL)
			return (NULL);
		ptr->content_size = fd;
		return (ptr);
	}
	while (ptr)
	{
		if (ptr->content_size == fd)
			return (ptr);
		if (!(ptr->next))
			break;
		ptr = ptr->next;
	}
	if ((ptr->next = ft_lstnew(s, BUFF_SIZE + 1)) == NULL)
		return (NULL);
	ptr->next->content_size = fd;
	return (ptr->next);
}

/*int 	ft_check_string(t_list **head)
{

	return (0);
}

void   ft_clean(arr[fd])
{
	free(arr[fd]);
}
*/

int		ft_read(t_list *head, const int fd, char **line)
{

}
/*{
	int num_read;

	while (!ft_check_string(arr))
		if (!ft_allocate_memory(arr))
		{
			ft_clean(arr[fd]);
			return (-1);
		}
	num_read = read(fd, arr, BUFF_SIZE);
	if (num_read == -1)
		return (-1);
	if (num_read != 1 && num_read != BUFF_SIZE)
		return (0);
	else
	{
		arr[BUFF_SIZE] = '\0';
	}
}*/

int		get_next_line(const int fd, char **line)
{
	int             i;
	static t_list   *head;
	t_list			*ptr;

	if (fd < 0 || !line || !(ptr = ft_check_list(&head, fd)))
		return (-1);
	i = ft_read(head, fd, line);
	if (i == -1 || i == 0)
		ft_clean(head, fd);
	//printf("fd = %zu\n", head->content_size);
	//if (head->next)
	//	printf("fd 2 = %zu\n", head->next->content_size);
	return (1);
}

/*int main()
{
	char *a;

	get_next_line(1, &a);
	get_next_line(2, &a);
}*/