/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:54:01 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/18 18:17:07 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

t_list	*ft_check_list(t_list **head, const int fd)
{
	t_list	*ptr;
	char	s[BUFF_SIZE + 1];

	ft_bzero(s, BUFF_SIZE + 1);
	ptr = *head;
	if (!ptr)
	{
		if ((ptr = ft_lstnew(s, BUFF_SIZE)) == NULL)
			return (NULL);
		ptr->content_size = fd;
		*head = ptr;
		return (ptr);
	}
	while (ptr)
	{
		if (ptr->content_size == (size_t) fd)
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

int		ft_buf_overwrite(t_list **ptr, char **line, int num_read)
{
	char	*tmp;
	char	*new_cont;

	if (num_read == BUFF_SIZE)
		tmp = ft_strchr((*ptr)->content, '\n');
	else
		tmp = ft_strchr((*ptr)->content, '\0');
	if (!(*line = ft_strnew(tmp - (char *)(*ptr)->content + 1)))
		return (-1);
	*line = ft_strnew(tmp - (char *)(*ptr)->content + 1);
	*line = ft_strncpy(*line, (*ptr)->content, tmp - (char *)(*ptr)->content);
	if (num_read == BUFF_SIZE)
	{
		if (!(new_cont = ft_strnew(ft_strlen((*ptr)->content)
				- (tmp - (char *)(*ptr)->content))))
			return (-1);
		ft_strcpy(new_cont, tmp + 1);
		free((*ptr)->content);
		(*ptr)->content = new_cont;
	}
	else
		*((char *)(*ptr)->content) = '\0';
	printf("");
	return (1);
}

int		ft_read(t_list **ptr, char **line)
{
	int		num_read;
	char	*str;

	while (!ft_strchr((*ptr)->content, '\n'))
	{
		if (!(str = ft_strnew(ft_strlen((*ptr)->content) + (int)BUFF_SIZE + 1)))
			return (-1);
		str = ft_strcpy(str, (*ptr)->content);
		num_read = read((*ptr)->content_size, ft_strchr(str, '\0'), BUFF_SIZE);
		if (num_read == -1)
			return (-1);
		if (num_read != (int)BUFF_SIZE)
			break ;
		free((*ptr)->content);
		(*ptr)->content = str;
	}
	if (num_read == 0 && *((char *)(*ptr)->content) == '\0')
		return (0);
	return (ft_buf_overwrite(ptr, line, num_read));
}

void	ft_clean(t_list **head, const int fd)
{
	t_list	*ptr;
	t_list	*tmp;

	tmp = *head;
	ptr = NULL;
	if (tmp->content_size == (size_t)fd)
	{
		*head = tmp->next;
		free(tmp);
	}
	while (!(tmp->content_size == (size_t)fd))
	{
		ptr = tmp;
		tmp = tmp->next;
	}
	ptr->next = tmp->next;
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static t_list	*head;
	t_list			*ptr;

	if (fd < 0 || !line || !(ptr = ft_check_list(&head, fd)))
		return (-1);
	i = ft_read(&ptr, line);
	printf("i = %d\n", i);
	if (i == -1 || i == 0)
		ft_clean(&head, fd);
	return (i);
}

int main(int argc, char **argv)
{
	int fd;
	char *str;
	int a;
	fd = open(argv[1], O_RDONLY);

	printf("i = %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	printf("i = %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	printf("i = %d\n", get_next_line(fd, &str));
	// printf("%s\n", str);
	// printf("%d ", get_next_line(fd, &str));
	// printf("%s\n", str);
	// while ((a = get_next_line(fd, &str)))
	// {
	// 	printf("a = %d = %s\n", a, str);
	// }
}
