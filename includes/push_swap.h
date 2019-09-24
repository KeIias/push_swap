/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:23:04 by algautie          #+#    #+#             */
/*   Updated: 2019/09/24 11:23:48 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	ps_swap(t_dlist **beg, t_dlist **beg_ins, int ins);
void	ps_push(t_dlist **from, t_dlist **to, t_dlist **beg_ins, int ins);
void	ps_rotate(t_dlist **beg, t_dlist **beg_ins, int ins);
void	ps_reverse_rotate(t_dlist **beg, t_dlist **beg_ins, int ins);
void	ch_swap(t_dlist **beg);
void	ch_push(t_dlist **from, t_dlist **to);
void	ch_rotate(t_dlist **beg);
void	ch_reverse_rotate(t_dlist **beg);
int		check_word(char *str);
int		check_args(int ac, char **av);
int		is_sorted(t_dlist *beg);
int		is_reverse_sorted(t_dlist *beg);
void	print_ins(t_dlist *beg_ins);
void	push_all(t_dlist **from, t_dlist **to, t_dlist **beg_ins, int ins);
void	normalize(t_dlist **beg);
void	pseudo_quick_sort(t_dlist **beg_a, t_dlist **beg_b, t_dlist **beg_ins);
void	optimize(t_dlist *beg_ins);

# define P_A 1
# define P_B 2
# define S_A 3
# define S_B 4
# define R_A 5
# define R_B 6
# define RR_A 7
# define RR_B 8
# define SS 9
# define RR 10
# define RRR 11

#endif
