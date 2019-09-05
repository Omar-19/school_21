/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:43:15 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 20:49:29 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strdup(const char *s1);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strncpy(char * dst, const char * src, size_t len);
char    *ft_strcat(char *s1, const char *s2);
char    *ft_strncat(char *s1, const char *s2, size_t n);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);

int main()
{
//	char c = '5';
//	char s[] = "1234567389";
//	printf("%s\n", ft_memchr(s, c, 9));
//	printf("%s\n", memchr(s, c, 9));

//	char s1[] = "qwert";
//	char s2[] = "qqert";
//	printf("%d\n", ft_memcmp(s1, s2, 4));
//	printf("%d\n", memcmp(s1, s2, 4));

//	char s[] = "\0";
//	printf("%lu\n", ft_strlen(s));
//	printf("%lu\n", strlen(s));

//	char s[] = "\0";
//	printf("%s\n", ft_strdup(s));
//	printf("%s\n", strdup(s));

//	char s2[] = "\0";
//	char s1[] = "qqert";
//	printf("%s\n", ft_strcpy(s1, s2));
//	printf("%s\n", strcpy(s1, s2));

//	char s2[] = "1234";
//	char s1[] = "qqert";
//	printf("%s\n", ft_strncpy(s1, s2, 0));
//	printf("%s\n", strncpy(s1, s2, 0));

//	char s1[] = "qqert";
//	char s2[] = "1234";
//	printf("%s\n", ft_strcat(s1, s2));
//	char p1[] = "qqert";
//	char p2[] = "1234";
//	printf("%s\n", strcat(p1, p2));

//	char s1[20] = "qer";
//	char s2[] = "1234";
//	printf("%s\n", ft_strncat(s1, s2, 5));
//	char p1[20] = "qer";
//	char p2[] = "1234";
//	printf("%s\n", strncat(p1, p2, 5));

//	char s[] = "1234";
//	char c = '7';
//	printf("%p\n", ft_strchr(s, c));
//	printf("%p\n", ft_strrchr(s, c));

	char csrc1[100] = "Geeksfor";
	printf("%s\n", memcpy(csrc1+5, csrc1, strlen(csrc1)+1));
	char csrc2[100] = "Geeksfor";
	printf("%s\n", memcpy(csrc2, csrc2+5, strlen(csrc2)+1));
}
