/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:12:34 by algautie          #+#    #+#             */
/*   Updated: 2019/09/24 10:58:54 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_dlist **beg, t_dlist **beg_ins)
{
	t_dlist	*tmp;
	int		a;
	int		b;
	int		c;

	while (!(is_sorted(*beg)))
	{
		tmp = *beg;
		a = tmp->value;
		b = tmp->next->value;
		c = tmp->next->next->value;
		if (a < b && a < c && b > c)
			ps_reverse_rotate(beg, beg_ins, RR_A);
		else if (a > b && b < c && c > a)
			ps_swap(beg, beg_ins, S_A);
		else if (a < b && a > c && b > c)
			ps_reverse_rotate(beg, beg_ins, RR_A);
		else if (a > b && a > c && b > c)
			ps_swap(beg, beg_ins, S_A);
		else if (a > b && a > c && b < c)
			ps_rotate(beg, beg_ins, R_A);
	}
}

int		get_lowest(t_dlist **beg)
{
	int		value;
	t_dlist	*tmp;

	tmp = *beg;
	value = tmp->value;
	while (tmp)
	{
		if (tmp->value < value)
			value = tmp->value;
		tmp = tmp->next;
	}
	return (value);
}

void	pseudo_quick_sort(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	int		lowest;
	int		pos;
	t_dlist	*tmp;

	if (is_sorted(*beg_a))
		return ;
	while (ft_lstlen(*beg_a) != 3)
	{
		lowest = get_lowest(beg_a);
		pos = 0;
		tmp = *beg_a;
		while (tmp->value != lowest && ++pos)
			tmp = tmp->next;
		while ((*beg_a)->value != lowest)
		{
			if (pos * 2 > ft_lstlen(*beg_a))
				ps_reverse_rotate(beg_a, beg_ins, RR_A);
			else
				ps_rotate(beg_a, beg_ins, R_A);
		}
		ps_push(beg_a, beg_b, beg_ins, P_B);
	}
	sort_three(beg_a, beg_ins);
	push_all(beg_b, beg_a, beg_ins, P_A);
}
