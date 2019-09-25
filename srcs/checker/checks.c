/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:58:53 by algautie          #+#    #+#             */
/*   Updated: 2019/09/25 11:39:28 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_word(char *str)
{
	int		i;
	long	tmp;

	i = -1;
	tmp = ft_atolong(str);
	if (ft_strlen(str) > 11 || tmp > 2147483647 || tmp < -2147483648)
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]) && !(i == 0 && str[i] == '-'))
			return (0);
	return (1);
}

int		check_args(int ac, char **av)
{
	int i;
	int *stack;

	stack = NULL;
	if (!(stack = (int*)malloc(sizeof(int) * (ac - 1))))
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!check_word(av[i]))
		{
			if (stack)
				free(stack);
			return (0);
		}
		stack[i - 1] = ft_atoi(av[i]);
	}
	ft_sort_integer_table(stack, ac - 1);
	i = ft_issorted(stack, ac - 1);
	if (stack)
		free(stack);
	return (i);
}

int		is_sorted(t_dlist *beg)
{
	t_dlist *tmp;

	tmp = beg;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
