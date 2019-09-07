/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:44:20 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/07 16:47:25 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int number;
	int sign;

	sign = 1;
	number = 0;
	while (*str == '\t' || *str == ' ' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + sign * (*str - '0');
		str++;
	}
	return (number);
}
