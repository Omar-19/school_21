/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:43:02 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/03 17:31:06 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_print_params(int arc, char **arv)
{
	int i;

	i = 1;
	while (i < arc)
	{
		ft_putstr(arv[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_sort_params(int arc, char **arv)
{
	int		i;
	int		j;
	char	*ptr;

	i = 1;
	while ((i + 1) < arc)
	{
		j = i + 1;
		while (j < arc)
		{
			if (ft_strcmp(arv[i], arv[j]) > 0)
			{
				ptr = arv[i];
				arv[i] = arv[j];
				arv[j] = ptr;
			}
			j++;
		}
		i++;
	}
	ft_print_params(arc, arv);
}

int		main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	return (0);
}
