#include "push_swap.h"

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

	if (!(stack = (int*)malloc(sizeof(int) * (ac - 1))))
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!check_word(av[i]))
		{
			free(stack);
			return (0);
		}
		stack[i - 1] = ft_atoi(av[i]);
	}
	ft_sort_integer_table(stack, ac - 1);
	i = ft_issorted(stack, ac - 1);
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

int		is_reverse_sorted(t_dlist *beg)
{
	t_dlist *tmp;

	tmp = beg;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_ins(t_dlist *beg_ins)
{
	t_dlist *tmp;

	tmp = beg_ins;
	while (tmp)
	{
		tmp->value == 1 ? ft_putendl("pa") : 0;
		tmp->value == 2 ? ft_putendl("pb") : 0;
		tmp->value == 3 ? ft_putendl("sa") : 0;
		tmp->value == 4 ? ft_putendl("sb") : 0;
		tmp->value == 5 ? ft_putendl("ra") : 0;
		tmp->value == 6 ? ft_putendl("rb") : 0;
		tmp->value == 7 ? ft_putendl("rra") : 0;
		tmp->value == 8 ? ft_putendl("rrb") : 0;
		tmp->value == 9 ? ft_putendl("ss") : 0;
		tmp->value == 10 ? ft_putendl("rr") : 0;
		tmp->value == 11 ? ft_putendl("rrr") : 0;
		tmp = tmp->next;
	}
}
