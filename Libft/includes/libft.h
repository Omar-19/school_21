/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:04:16 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/07 17:52:08 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);

#endif
