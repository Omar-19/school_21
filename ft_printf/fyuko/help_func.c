#include "header.h"

void	ft_lst_delet(t_string **alst)
{
	t_string *nxt;
	t_string *tmp;

	if (alst != NULL)
	{
		nxt = *alst;
		while (nxt)
		{
			tmp = nxt->next;
			free(nxt);
			nxt = tmp;
		}
		free(*alst);
		*alst = NULL;
	}
}