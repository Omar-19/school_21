#include "../include/header_ps.h"

int main(int ac, char **av)
{
	t_lst   *a;
	t_lst   *b;
	t_lst   *c;
	int		f;

	a = NULL;
	b = NULL;
	f = 0;
	if (ac == 1 || !is_av_valid(ac, av))
	{
		ft_error(NULL, NULL);
        return (0);
	}
	else if (ac == 2)
		a = read_str_stack(av[1], a);
	else
		a = read_stack(av, ac, a);
	// printf("\n");
	check_valid_elems(a);
	is_sort(&a, &b);
	c = a;
	printf("-----A-----\n");
	while (c)
	{
		printf("num = %lld\n", c->num);
		c = c->next;
	}
	printf("-----------\n");
	c = b;
	printf("-----B-----\n");
	while (c)
	{
		printf("num = %lld\n", c->num);
		c = c->next;
	}
	printf("-----------\n");
	return (0);
}