#include "../include/header_ps.h"

t_lst	*ft_del_elem(char **str, t_lst *ptr)
{
	free(*str);
	free(ptr);
	return (NULL);
}

t_lst	*creat_el(char *av)
{
	t_lst	*tmp;
	char	*p;
	char	*str;

	p = NULL;
	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	tmp->num = atoi(av);
	// (tmp->num > 2147483647 || tmp->num < -2147483648) ? (ft_error(tmp, NULL)) : 0;
	str = ft_itoa(tmp->num);
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