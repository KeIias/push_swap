#include "push_swap.h"

void	swap(t_dlist **beg)
{
	t_dlist	*tmp;

	tmp = *beg;
	if (ft_lstlen(tmp) >= 2)
		ft_swap(&tmp->value, &tmp->next->value);
}
