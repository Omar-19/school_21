#include "../include/header_ps.h"

t_lst	*ft_del_elem(char **str, t_lst *ptr)
{
	free(*str);
	free(ptr);
	return (NULL);
}

long long int	ft_atoi_long(const char *str)
{
	long long int	number;
	int				sign;

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

t_lst	*creat_el(char *av, t_lst *a)
{
	t_lst	*tmp;
	char	*p;
	char	*str;

	p = NULL;
	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	tmp->num = ft_atoi_long(av);
	// printf("->num = %lld\n", tmp->num);
	(tmp->num > 2147483647 || tmp->num < -2147483648) ? (ft_error(a, NULL)) : 0;
	str = ft_itoa(tmp->num);
	// printf("s === %s\n", str);
	if ((p = ft_strchr(av, ' ')))
	{
		if (ft_strncmp(av, str, p - av))
			return (ft_del_elem(&str, tmp));
	}
	else
	{
		if (ft_strcmp(av, str))
			return (ft_del_elem(&str, tmp));
	}
	free(str);
	tmp->next = NULL;
	return (tmp);
}