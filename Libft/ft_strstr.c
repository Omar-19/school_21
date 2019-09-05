/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:15:37 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 19:20:20 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *str;
	char *to_find;
	char *a;
	char *b;

	str = (char *)haystack;
	to_find = (char *)needle;
	while (*str != '\0')
	{
		a = str;
		b = to_find;
		while (*a == *b || *to_find == '\0')
		{
			a++;
			b++;
			if (*b == '\0')
				return (str);
		}
		str++;
	}
	return (NULL);
}
