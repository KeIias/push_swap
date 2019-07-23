#include "push_swap.h"
#include <stdio.h>

static int		check_word(char *str)
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

static int		check_args(int ac, char **av)
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

int				main(int ac, char **av)
{
	int		i;
	t_dlist	*beg_a;
	t_dlist	*beg_b;

	if (!check_args(ac, av) || ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	beg_a = ft_lst_create_elem(ft_atoi(av[1]));
	beg_b = NULL;
	i = 1;
	while (++i < ac)
		ft_lst_push_back(&beg_a, ft_atoi(av[i]));
	ft_lst_print(beg_a);
	push(&beg_a, &beg_b);
	rotate(&beg_a);
	push(&beg_a, &beg_b);
	rotate(&beg_a);
	rotate(&beg_a);
	rotate(&beg_a);
	push(&beg_a, &beg_b);
	rotate(&beg_a);
	rotate(&beg_a);
	rotate(&beg_a);
	swap(&beg_a);
	reverse_rotate(&beg_a);
	push(&beg_b, &beg_a);
	push(&beg_b, &beg_a);
	push(&beg_b, &beg_a);
	ft_putchar('\n');
	ft_lst_print(beg_a);
	ft_putchar('\n');
	ft_lst_print(beg_b);
	//apply_commands(beg_a, beg_b);
}
