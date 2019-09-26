#include "header.h"

int		ft_write(const char *str, const size_t num)
{
	write(1, str, num);
	return (num);
}

int		ft_repeat(const char c, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_write(&c, 1);
		++i;
	}
	return (i);
}

int		get_arg(const char *str, size_t num, int val, va_list elem)
{
	if (*str == '%' && val)
		//
	return (ft_write(str, num));
}

int		ft_is_conversion(const char c)
{
	return (!(pf_strchr("sSpdDioOuUxXcClL%", c) == NULL));
}

int		ft_is_flag(const char c)
{
	return (!(pf_strchr("#0-+' ", c) == NULL));
}

int		ft_is_precision(const char c)
{
	return (!(pf_strchr("*.", c) == NULL));
}

int		ft_is_num(const char c)
{
	return (c >= '0' && c <= '9')
}

int			ft_is_valid_param(const char c)
{
	return (ft_is_conversion(c) || ft_is_flag(c) ||
			ft_is_num(c) || ft_is_precision(c));
}

int		check_prc(const char *str, size_t *i, int *val)
{
	if (!str[*i])
		return (1);
		//проверка на принадлежность к какому-либо типу кроме символов
	while (str[*i] && ft_is_valid_param(str[*i]) && !ft_is_conversion(str[*i]))
		(*i)++;
		//символ:
	if ((*valid = str[*i] && ft_is_valid_param(str[*i])))
		(*i)++;
	else
		return (1);
	return (0);
}

// подсчитывание числа выведеннных символов
// -> get

int		print_elem(const char *str, va_list elem)
{
	size_t	i;
	size_t	begin;
	int		count;
	int		val;

	i = 0;
	count = 0;
	while (str[i])
	{
		begin = i;
		val = 0;
		if (str[i] == %)
		{
			i++;
			if (check_prc(str, &i, &val))
				continue;
		}
		else
			while (str[i] && str[i] != '%')
				++i;
		// get_arg - 
		count += get_arg(str + begin, i - begin, val, elem)
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list	elem;
	int		result;

	va_start(elem, format);
	result = print_elem(format, elem);
	va_end(elem);
	return (result);
}