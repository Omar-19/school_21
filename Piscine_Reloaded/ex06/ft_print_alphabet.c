/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:23:34 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/02 18:38:20 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int		i;
	char	a;

	i = 0;
	a = 'a';
	while (i < 26)
	{
		ft_putchar(a + i);
		i++;
	}
}
