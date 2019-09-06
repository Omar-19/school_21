/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:26:26 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/06 14:32:01 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	while (i > 0)
	{
		i--;
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
