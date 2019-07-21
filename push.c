#include "push_swap.h"

void	push(t_dlist **from, t_dlist **to)
{
	t_dlist *tmp;

	if (*from != NULL)
	{
		tmp = *from;
		ft_lst_push_front(&*to, tmp->value);
		*from = tmp->next;
	}
}
