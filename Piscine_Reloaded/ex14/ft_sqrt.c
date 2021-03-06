/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:42:19 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/03 12:40:54 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}
