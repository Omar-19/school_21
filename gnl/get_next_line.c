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
	
	ptr = *head;
	if (!ptr)
	{
		if ((ptr = ft_lstnew("\0", 1)) == NULL)
			return (NULL);
		ptr->content_size = fd;
		*head = ptr;
		return (ptr);
	}
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
			return (ptr);
		if (!(ptr->next))
			break;
		ptr = ptr->next;
	}
	if ((ptr->next = ft_lstnew("\0", 1)) == NULL)
		return (NULL);
	ptr->next->content_size = fd;
	return (ptr->next);
}

int		ft_buf_overwrite(t_list **ptr, char **line)
{
	char	*tmp;
	//char	*new_cont;
	int		len;
	//int		len_content;
	char *a;

	a = (*ptr)->content;
	//len_content = ft_strlen((*ptr)->content);
	//printf("ptr->c1 = %s\n", (*ptr)->content);
	if (ft_strchr((*ptr)->content, '\n'))
		tmp = ft_strchr((*ptr)->content, '\n');
	else
		tmp = ft_strchr((*ptr)->content, '\0');
	//printf("ptr->c2 = %s\n", (*ptr)->content);
	len = (tmp - (char *)(*ptr)->content);
	//printf("ptr->c3 = %s\n", (*ptr)->content);
	//printf("a3 = %p\n", a);
	if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	//*line = ft_strnew(tmp - (char *)(*ptr)->content + 1);
	//*line = ft_strncpy(*line, (*ptr)->content, tmp - (char *)(*ptr)->content);
	//printf("len1 = %d\n", len);
	//printf("ptr->c4 = %s\n", (*ptr)->content);
	//printf("a4 = %p\n", a);
	*line = ft_strncpy(*line, (*ptr)->content, len);
	*(*line + len) = '\0';
	//printf("line = %s\n", *line);
	len = ft_strlen((*ptr)->content) - len;
	//printf("len2 = %d\n", len);
	if (len != 0)
		(*ptr)->content = ft_memmove((*ptr)->content, tmp + 1, len);
	else
	{
		// умирает где-то тут
		(*ptr)->content = ft_memmove((*ptr)->content, tmp, 1);
		//free((*ptr)->content);
		//(*ptr)->content = ft_strnew(1);
	}
	//printf("ptr->c(f) = %d ? == %d\n", *((char *)(*ptr)->content), '\n');
	//*((char *)((*ptr)->content + len)) = '\0';
	//printf("len = %d\n", len);
	/*if (num_read == BUFF_SIZE)
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
	*/
	return (1);
	/*
	len = (tmp - (char *)(*ptr)->content);
	if (!(*line = ft_strnew(len)))
		return (-1);
	// *line = ft_strnew(tmp - (char *)(*ptr)->content);
	*line = ft_strncpy(*line, (*ptr)->content, len);
	*(*line + len) = '\0';
	len = ft_strlen((*ptr)->content) - len;
	if (len != 0)
		(*ptr)->content = ft_memmove((*ptr)->content, tmp + 1, len);
	*((char *)((*ptr)->content + len)) = '\0';*/
}

int		ft_read(t_list **ptr, char **line)
{
	int		num_read;
	char	str[BUFF_SIZE + 1];
	char	*tmp;

	while (!ft_strchr((*ptr)->content, '\n'))
	{
		//if (!(str = ft_strnew(ft_strlen((*ptr)->content) + (int)BUFF_SIZE + 1)))
		//	return (-1);
		//str = ft_strcpy(str, (*ptr)->content);
		//num_read = read((*ptr)->content_size, ft_strchr(str, '\0'), BUFF_SIZE);
		num_read = read((*ptr)->content_size, str, BUFF_SIZE);
		str[num_read] = '\0';
		if (num_read == -1)
			return (-1);
		//if (num_read != (int)BUFF_SIZE)
		//	break ;
		if (num_read == 0)
			break;
		//free((*ptr)->content);
		if (!(tmp = ft_strjoin((*ptr)->content, str)))
			return (-1);
		free((*ptr)->content);
		(*ptr)->content = tmp;
		//printf("num_read = %d\n", num_read);
	}
	//printf("*((char *)(*ptr)->content) = %d == %d\n", *((char *)(*ptr)->content), '\0');
	if (*((char *)(*ptr)->content) == '\0')// || 
		//*((char *)(*ptr)->content) == 10))
		return (0);
	return (ft_buf_overwrite(ptr, line));
}

void	ft_clean(t_list **head, const int fd, char **line)
{
	t_list	*ptr;
	t_list	*tmp;

	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	tmp = *head;
	ptr = NULL;
	if (tmp->content_size == (size_t)fd)
	{
		*head = tmp->next;
		free(tmp);
		return ;
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
	if (i == -1 || i == 0)
		ft_clean(&head, fd, line);
	return (i);
}
/*
int main(int argc, char **argv)
{
	int fd;
	char *str;
	int a;
	fd = open(argv[1], O_RDONLY);

	printf("i = %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	free(str);
	//printf("%d ? == %d\n", str[7], '\0');
	printf("i = %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	free(str);
	//printf("%d ? == %d\n", str[7], '\0');
	printf("i = %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	free(str);
	//printf("%d ? == %d\n", str[0], '\0');
}*/
	//printf("%s\n", str);
	/*fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	printf("test 1 i = %d\n", get_next_line(fd1, &str));
	printf("%s\n", str);
	printf("test 2 i = %d\n", get_next_line(fd2, &str));
	printf("%s\n", str);
	printf("test 2 i = %d\n", get_next_line(fd2, &str));
	printf("%s\n", str);
	printf("test 2 i = %d\n", get_next_line(fd2, &str));
	printf("%s\n", str);
	printf("i = %d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);
	// printf("%d ", get_next_line(fd, &str));
	// printf("%s\n", str);
	// while ((a = get_next_line(fd, &str)))
	// {
	// 	printf("a = %d = %s\n", a, str);
	// }*/
//}
