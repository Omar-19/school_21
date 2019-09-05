/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:51:49 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 16:18:50 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t  ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char			*p;
	char			*str;
	unsigned char	*ptr;

	ptr = (unsigned char *)s1;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
	{
		p = str;
		while (*ptr != '\0')
		{
			*str = *ptr;
			ptr++;
			str++;
		}
		*str = '\0';
		return (p);
	}
	return (NULL);
}
