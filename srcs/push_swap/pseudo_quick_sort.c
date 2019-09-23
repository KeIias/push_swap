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
	while (!(is_sorted(*beg)))
	{
		a = tmp->value;
		b = tmp->next->value;
		c = tmp->next->next->value;
		ft_putnbr(a);
		ft_putchar('\n');
		ft_putnbr(b);
		ft_putchar('\n');
		ft_putnbr(c);
		ft_putchar('\n');
		ft_putchar('\n');
		if (a < b && a < c && b > c)
		{
			ft_putstr("Wut");
			ps_reverse_rotate(beg, beg_ins, RR_A);
			ft_putstr("Face");
		}
		else if (a > b && b < c && c > a)
		{
			ft_putstr("Pog");
			ps_swap(beg, beg_ins, S_A);
			ft_putstr("Champ");
		}
		else if (a > b && a > c && b > c)
			ps_reverse_rotate(beg, beg_ins, RR_A);
		else if (a > b && a > c && b > c)
			ps_swap(beg, beg_ins, S_A);
		else if (a > b && a > c && b < c)
			ps_rotate(beg, beg_ins, R_A);
	}
}

void	pseudo_quick_sort(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	(void)beg_b;
	sort_three(beg_a, beg_ins);
}
