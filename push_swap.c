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
		push(beg_a, beg_b, beg_ins, P_B);
	rotate(beg_a, beg_ins, R_A);
	while (ft_lstlen(*beg_b) != len / 2)
	{
		//ft_lst_print(*beg_a);
		//ft_lst_print(*beg_b);
		//ft_lst_print(*beg_ins);
		//ft_putchar('\n');
		if ((*beg_a)->value < mid)
			push(beg_a, beg_b, beg_ins, P_B);
		rotate(beg_a, beg_ins, R_A);
	}
}

int		get_first_one(t_dlist **beg_a, int mask)
{
	t_dlist *tmp;

	tmp = *beg_a;
	while (tmp)
	{
		if (tmp->value & mask)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

void	radix(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins)
{
	int mask;
	int first_one;

	mask = 1;
	while (!is_sorted(*beg_a) || ft_lstlen(*beg_b) != 0)
	{
		if ((first_one = get_first_one(beg_a, mask)) != 0)
		{

		}
		mask *= 2;
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
	//ft_lst_print(beg_a);
	//ft_putchar('\n');
	//ft_lst_print(beg_b);
	//ft_putchar('\n');
	//ft_lst_print(beg_ins);
	print_ins(beg_ins);
}
