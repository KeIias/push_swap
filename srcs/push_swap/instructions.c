/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:58:59 by algautie          #+#    #+#             */
/*   Updated: 2019/09/23 12:14:37 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_push(t_dlist **from, t_dlist **to, t_dlist **beg_ins, int ins)
{
	t_dlist *tmp;

	if (*from != NULL)
	{
		tmp = *from;
		ft_lst_push_front(&*to, tmp->value);
		*from = tmp->next;
		ft_lst_push_back(beg_ins, ins);
	}
}

void	ps_swap(t_dlist **beg, t_dlist **beg_ins, int ins)
{
	t_dlist	*tmp;

	tmp = *beg;
	if (ft_lstlen(tmp) >= 2)
		ft_swap(&tmp->value, &tmp->next->value);
	ft_lst_push_back(beg_ins, ins);
}

void	ps_rotate(t_dlist **beg, t_dlist **beg_ins, int ins)
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
	ft_lst_push_back(beg_ins, ins);
}

void	ps_reverse_rotate(t_dlist **beg, t_dlist **beg_ins, int ins)
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
	ft_lst_push_back(beg_ins, ins);
}

void	push_all(t_dlist **from, t_dlist **to, t_dlist **beg_ins, int ins)
{
	while (ft_lstlen(*from) != 0)
		push(from, to, beg_ins, ins);
}
