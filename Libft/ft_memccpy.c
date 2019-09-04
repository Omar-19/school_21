/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:59:52 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/04 21:15:53 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
	}
	*ptr1 = '\0';
	return (dst);
}
