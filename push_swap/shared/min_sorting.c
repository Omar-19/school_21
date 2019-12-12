#include "../include/header_ps.h"

void	ft_create_b(t_lst **a, t_lst **b, int n)
{
	while (n-- >= 3)
		pb(a, b, 1);
	ft_sort_three(*a);
}

void	ft_sort_three(t_lst *a)
{
	if (check(a))
		return ;
	else if (a->num < a->next->num && a->num > a->next->next->num)
		rra(a, 1);
	else if (a->num > a->next->next->num && a->next->num < a->next->next->num)
		ra(a, 1);
	else
	{
		sa(a, 1);
		if (a->num < a->next->num && a->num > a->next->next->num)
			rra(a, 1);
		else if (a->num > a->next->next->num && a->next->num < a->next->next->num)
			ra(a, 1);
		else
			return ;
	}
}

void	ft_min_sort(t_lst *a, int i)
{
	if (i == 0)
	{
		ft_clear_stack(a);
		exit(0);
	}
	else if (i == 1)
		sa(a, 1);
	else
		ft_sort_three(a);
	ft_clear_stack(a);
	exit(0);
}
