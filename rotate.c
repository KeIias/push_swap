#include "push_swap.h"

void	rotate(t_dlist **beg)
{
	t_dlist *tmp;

	if (ft_lstlen(*beg) > 1)
	{
		tmp = *beg;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *beg;
		tmp = *beg;
		*beg = tmp->next;
		tmp->next = NULL;
	}
}
