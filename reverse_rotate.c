#include "push_swap.h"

void	reverse_rotate(t_dlist **beg)
{
	t_dlist *tmp;

	tmp = *beg;
	if (ft_lstlen(tmp) > 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *beg;
		*beg = tmp;
		while (tmp->next != *beg)
			tmp = tmp->next;
		tmp->next = NULL;
	}
}
