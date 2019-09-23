#include "push_swap.h"

void	apply_commands(t_dlist **beg_a, t_dlist **beg_b)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, "sa") == 0)
			swap(beg_a, NULL, S_A);
		else if (ft_strcmp(line, "sb") == 0)
			swap(beg_a, NULL, S_B);
		else if (ft_strcmp(line, "ss") == 0)
		{
			swap(beg_a, NULL, S_A);
			swap(beg_b, NULL, S_B);
		}
		else if (ft_strcmp(line, "pa"))
			push(beg_b, beg_a, NULL, P_A);
		else if (ft_strcmp(line, "pb"))
			push(beg_a, beg_b, NULL, P_B);
		else if (ft_strcmp(line, "ra"))
			rotate(beg_a, NULL, R_A);
		else if (ft_strcmp(line, "rb"))
			rotate(beg_b, NULL, R_B);
		else if (ft_strcmp(line, "rr"))
		{
			rotate(beg_a, NULL, R_A);
			rotate(beg_b, NULL, R_B);
		}
		else if (ft_strcmp(line, "rra"))
			reverse_rotate(beg_a, NULL, RR_A);
		else if (ft_strcmp(line, "rrb"))
			reverse_rotate(beg_b, NULL, RR_B);
		else if (ft_strcmp(line, "rrr"))
		{
			reverse_rotate(beg_a, NULL, RR_A);
			reverse_rotate(beg_b, NULL, RR_B);
		}
		else
		{
			write(2, "Error\n", 6);
			return ;
		}
	}
	if (is_sorted(*beg_a) && ft_lstlen(*beg_b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		main(int ac, char **av)
{
	int		i;
	t_dlist	*beg_a;
	t_dlist	*beg_b;

	if (!check_args(ac, av) || ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	beg_a = ft_lst_create_elem(ft_atoi(av[1]));
	beg_b = NULL;
	i = 1;
	while (++i < ac)
		ft_lst_push_back(&beg_a, ft_atoi(av[i]));
	ft_lst_print(beg_a);
	apply_commands(&beg_a, &beg_b);
}
