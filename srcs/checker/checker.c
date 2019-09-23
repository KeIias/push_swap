#include "../../includes/push_swap.h"

void	apply_commands(t_dlist **beg_a, t_dlist **beg_b)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, "sa") == 0)
			ch_swap(beg_a);
		else if (ft_strcmp(line, "sb") == 0)
			ch_swap(beg_b);
		else if (ft_strcmp(line, "ss") == 0)
		{
			ch_swap(beg_a);
			ch_swap(beg_b);
		}
		else if (ft_strcmp(line, "pa") == 0)
			ch_push(beg_b, beg_a);
		else if (ft_strcmp(line, "pb") == 0)
			ch_push(beg_a, beg_b);
		else if (ft_strcmp(line, "ra") == 0)
			ch_rotate(beg_a);
		else if (ft_strcmp(line, "rb") == 0)
			ch_rotate(beg_b);
		else if (ft_strcmp(line, "rr") == 0)
		{
			ch_rotate(beg_a);
			ch_rotate(beg_b);
		}
		else if (ft_strcmp(line, "rra") == 0)
			ch_reverse_rotate(beg_a);
		else if (ft_strcmp(line, "rrb") == 0)
			ch_reverse_rotate(beg_b);
		else if (ft_strcmp(line, "rrr") == 0)
		{
			ch_reverse_rotate(beg_a);
			ch_reverse_rotate(beg_b);
		}
		else
		{
			write(2, "Error\n", 6);
			get_next_line(0, NULL);
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

	if (ac == 1)
		return (0);
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
	apply_commands(&beg_a, &beg_b);
}
