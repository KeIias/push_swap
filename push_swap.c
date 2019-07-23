#include "push_swap.h"

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
}
