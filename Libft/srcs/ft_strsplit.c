/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:36:26 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/08 20:49:11 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	word_count(char const *s, char c, int *i)
{
	*i = 0;
	printf("word count = %d\n", *i);
	while (*s != '\0')
	{
		printf("word count = %d\n", *i);
		while (*s == c)
			++s;
		if (*s != '\0')
		{
			++(*i);
			while (*s != c && *s != '\0')
				++s;
		}
	}
	printf("word count = %d\n", *i);
}
/*
static void word_length(char const *s, char c, int *j)
{
	*j = 0;
	while (*s == c)
		++s;
	if (*s != '\0')
		while (*s != c && *s != '\0')
		{
			++(*j);
			++s;
		}
	printf("word length = %d\n", *j);
}
*/
char		**ft_strsplit(char const *s, char c)
{
	int		*i;
	int		*j;
	int		k;
	char	**str;

	k = 0;
//	word_count(s, c, i);
//	if (!(str = (char **)malloc(sizeof(char *) * *i + 1)))
//		return (NULL);
/*	while (*i > 0)
	{
		word_length(s, c, j);
		if (!(str[k] = (char *)malloc(sizeof(char *) * *j + 1)))
			return (NULL);
		k++;
		--(*i);
	}*/
}

int main()
{
	char *s = " aaa bb  cccc        d                 ";

//	ft_strsplit(s, ' ');
}
