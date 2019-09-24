/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:11:39 by algautie          #+#    #+#             */
/*   Updated: 2019/09/24 15:24:04 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_command(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")
		&& ft_strcmp(line, "ra") && ft_strcmp(line, "ra")
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
		&& ft_strcmp(line, "rr") && ft_strcmp(line, "rrr")
		&& ft_strcmp(line, "ss"))
		return (0);
	return (1);
}

void	apply_command(t_dlist **beg_a, t_dlist **beg_b, char *line)
{
	!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss") ? ch_swap(beg_a) : 0;
	!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss") ? ch_swap(beg_b) : 0;
	!ft_strcmp(line, "pa") ? ch_push(beg_b, beg_a) : 0;
	!ft_strcmp(line, "pb") ? ch_push(beg_a, beg_b) : 0;
	!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr") ? ch_rotate(beg_a) : 0;
	!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr") ? ch_rotate(beg_b) : 0;
	!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr")
		? ch_reverse_rotate(beg_a) : 0;
	!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr")
		? ch_reverse_rotate(beg_b) : 0;
}

void	apply_commands(t_dlist **beg_a, t_dlist **beg_b)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (!check_command(line))
		{
			write(2, "Error\n", 6);
			get_next_line(0, NULL);
			free(line);
			return ;
		}
		apply_command(beg_a, beg_b, line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
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
	if (!check_args(ac, av) || ac < 2
		|| !(beg_a = ft_lst_create_elem(ft_atoi(av[1]))))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	beg_b = NULL;
	i = 1;
	while (++i < ac)
		ft_lst_push_back(&beg_a, ft_atoi(av[i]));
	apply_commands(&beg_a, &beg_b);
	ft_lst_free(beg_a);
	ft_lst_free(beg_b);
}
