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

void	swap(t_dlist **beg)
{
	t_dlist	*tmp;

	tmp = *beg;
	if (ft_lstlen(tmp) >= 2)
		ft_swap(&tmp->value, &tmp->next->value);
}

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
