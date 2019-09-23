/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:11:30 by algautie          #+#    #+#             */
/*   Updated: 2019/09/23 17:11:31 by algautie         ###   ########.fr       */
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
