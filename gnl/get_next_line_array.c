/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:27:24 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/16 15:27:29 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_check_string(static char *arr)
{
	if (!arr)
	{
		while (*arr != '\0')
			if (*(arr++) == '\n')
				return (1);
	}
	return (0);
}

int    ft_allocate_memory()
{
	if (!arr)
	{
		if (!(arr = (char *) malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (0);
	}
	else
}

void   ft_clean(arr[fd])
{
	free(arr[fd]);
}

int ft_read(static char *arr, char **line)
{
	int num_read;

	// проверка на существование строки в arr
	// при отсуствии довыделение памяти размером BUFF_SIZE
	// совместить --- ?
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
}

int get_next_line(const int fd, char **line)
{
    int             i;
    static char     *arr[10240];

    i = ft_read(arr[fd], line)
    if (i == -1 || i == 0)
    	ft_clean(arr[fd]);
    return (i);
}