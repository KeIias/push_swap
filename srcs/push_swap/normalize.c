/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:11:30 by algautie          #+#    #+#             */
/*   Updated: 2019/09/25 12:14:36 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	optimize(t_dlist *beg_ins)
{
	t_dlist *tmp;

	if (ft_lstlen(beg_ins) < 10)
		return ;
	tmp = beg_ins;
	while (tmp->next)
	{
		if ((tmp->value == P_A && tmp->next->value == P_B)
			|| (tmp->value == P_B && tmp->next->value == P_A)
			|| (tmp->value == R_A && tmp->next->value == RR_A)
			|| (tmp->value == RR_A && tmp->next->value == R_A)
			|| (tmp->value == R_B && tmp->next->value == RR_B)
			|| (tmp->value == RR_B && tmp->next->value == R_B))
		{
			tmp->value = -1;
			tmp->next->value = -1;
			tmp = beg_ins;
		}
		tmp = tmp->next;
	}
}
