#include "../include/header_ps.h"

int main(int ac, char **av)
{
	t_lst		*a;
	t_lst		*b;
	t_lst		*c;
	t_insert	tmp;
	int		f;

	a = NULL;
	b = NULL;
	tmp.len_a = 0;
	f = 0;
	if (ac == 1)
        return (0);
	if (!is_av_valid(ac, av))
	{
		// printf("S\n");
		ft_error(NULL, NULL);
	}
	else if (ac == 2)
	{
		// printf("S\n");
		a = read_str_stack(av[1], a);
		// printf("S\n");
	}
	else
	{
		// printf("S\n");
		a = read_stack(av, ac, a);
		// printf("S\n");
	}
	// printf("\n");
	check_valid_elems(a);
	is_sort(&a, &b);
	c = a;
	insertion_sort(&a, &b, tmp);
	// printf("-----A-----\n");
	// while (c)
	// {
	// 	printf("num = %lld\n", c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
	// c = b;
	// printf("-----B-----\n");
	// while (c)
	// {
	// 	printf("num = %lld\n", c->num);
	// 	c = c->next;
	// }
	// printf("-----------\n");
	ft_clear_stack(a);
	ft_clear_stack(b);
	return (0);
}