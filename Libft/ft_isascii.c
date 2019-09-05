/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:00:00 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 20:02:14 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isascii(int c)
{
	return (c >= 0 && c <= 127);
}
