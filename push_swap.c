#include "push_swap.h"

int		get_mid(t_dlist *beg)
{
	t_dlist	*tmp;
	int		len;
	int		*tab;
	int		ret;
	int		i;

	tmp = beg;
	len = ft_lstlen(tmp);
	if (len == 1)
		return ((int)tmp->value);
	tab = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
	}
	ft_sort_integer_table(tab, len);
	ret = tab[(len / 2)];
	free(tab);
	return (ret);
}

void	separate_in_two(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	int		mid;
	int		len;

	mid = get_mid(*beg_a);
	len = ft_lstlen(*beg_a);
	if ((*beg_a)->value < mid)
	{
		push(beg_a, beg_b);
		ft_lst_push_front(beg_ins, P_B);
	}
	rotate(beg_a);
	ft_lst_push_front(beg_ins, R_A);
	while (ft_lstlen(*beg_b) != len / 2)
	{
		ft_lst_print(*beg_a);
		ft_lst_print(*beg_b);
		ft_lst_print(*beg_ins);
		ft_putchar('\n');
		if ((*beg_a)->value < mid)
		{
			push(beg_a, beg_b);
			ft_lst_push_front(beg_ins, P_B);
		}
		rotate(beg_a);
		ft_lst_push_front(beg_ins, R_A);
	}
}

void	sort_both(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	while (!is_sorted(*beg_a) || !is_reverse_sorted(*beg_b))
	{
		if ((*beg_a)->value > (*beg_a)->next->value)
		{
			if (((*beg_b)->value < (*beg_b)->next->value))
			{
				swap(beg_a);
				swap(beg_b);
				ft_lst_push_front(beg_ins, SS);
			}
			else
			{
				swap(beg_a);
				ft_lst_push_front(beg_ins, S_A);
			}
		}
		else if ((*beg_b)->value < (*beg_b)->next->value)
		{
			swap(beg_b);
			ft_lst_push_front(beg_ins, S_B);
		}
		if (!is_sorted(*beg_a) && !is_reverse_sorted(*beg_b))
		{
			rotate(beg_a);
			rotate(beg_b);
			ft_lst_push_front(beg_ins, RR);
		}
		else if (!is_sorted(*beg_a))
		{
			rotate(beg_a);
			ft_lst_push_front(beg_ins, R_A);
		}
		else if (!is_reverse_sorted(*beg_b))
		{
			rotate(beg_b);
			ft_lst_push_front(beg_ins, R_B);
		}
		ft_lst_print(*beg_a);
		ft_lst_print(*beg_b);
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_dlist	*beg_a;
	t_dlist	*beg_b;
	t_dlist	*beg_ins;

	if (!check_args(ac, av) || ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	beg_a = ft_lst_create_elem(ft_atoi(av[1]));
	beg_b = NULL;
	beg_ins = NULL;
	i = 1;
	while (++i < ac)
		ft_lst_push_back(&beg_a, ft_atoi(av[i]));
	separate_in_two(&beg_a, &beg_b, &beg_ins);
	sort_both(&beg_a, &beg_b, &beg_ins);
	ft_lst_print(beg_a);
	ft_lst_print(beg_b);
	ft_lst_print(beg_ins);
}
