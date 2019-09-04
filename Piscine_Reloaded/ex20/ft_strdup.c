/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:14:35 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/03 15:38:49 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	return (*str) ? ft_strlen(++str) + 1 : 0;
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	i = ft_strlen(src);
	c = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
