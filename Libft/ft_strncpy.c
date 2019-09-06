/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:41:35 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/06 14:30:56 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned char	*str;
	char			*ptr;
	int				f;

	f = 0;
	str = (unsigned char *)src;
	ptr = dst;
	while (len > 0)
	{
		if (*str == '\0')
			f = 1;
		if (f == 0)
			*ptr = *str;
		else
			*ptr = '\0';
		ptr++;
		str++;
		len--;
	}
	*ptr = '\0';
	return (dst);
}
