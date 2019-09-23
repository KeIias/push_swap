/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:12:34 by algautie          #+#    #+#             */
/*   Updated: 2019/09/23 17:23:55 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_dlist **beg, t_dlist **beg_ins)
{
	t_dlist *tmp;
	int a;
	int b;
	int c;

	tmp = *beg;
	a = tmp->value;
	b = tmp->next->value;
	c = tmp->next->next->value;
	if (is_sorted(*beg))
		return ;
}

void	pseudo_quick_sort(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	
}
