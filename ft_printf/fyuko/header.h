#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_string
{
	const char		*str;
	size_t			len;
    struct s_string	*next;
}					t_string;

void				ft_lst_delet(t_string **alst);
t_string			*ft_lst_new(char const *ptr);
t_string			*ft_lst_push_back(char const *ptr, t_string *elem);
int					ft_is_valid_param(const char c);
int					print_elem(const char *str, va_list elem);

#endif