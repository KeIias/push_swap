#include "push_swap.h"

void	normalize(t_dlist **beg)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;
	int		i;
	int		len;

	i = -1;
	tmp = *beg;
	len = ft_lstlen(tmp);
	while (++i != len)
	{
		tmp = *beg;
		while (tmp && tmp->info == 'n')
			tmp = tmp->next;
		tmp2 = tmp;
		tmp = *beg;
		while (tmp)
		{
			tmp = tmp->next;
			if (tmp && tmp->info != 'n' && tmp->value < tmp2->value)
				tmp2 = tmp;
		}
		tmp2->value = i;
		tmp2->info = 'n';
	}
}
