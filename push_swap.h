#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

void	swap(t_dlist **beg, t_dlist **beg_ins, int ins);
void	push(t_dlist **from, t_dlist **to, t_dlist **beg_ins, int ins);
void	rotate(t_dlist **beg, t_dlist **beg_ins, int ins);
void	reverse_rotate(t_dlist **beg, t_dlist **beg_ins, int ins);
int		check_word(char *str);
int		check_args(int ac, char **av);
int		is_sorted(t_dlist *beg);
int		is_reverse_sorted(t_dlist *beg);
void	print_ins(t_dlist *beg_ins);
void	push_all(t_dlist **from, t_dlist **to, t_dlist ** beg_ins, int ins);
void	normalize(t_dlist **beg);

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
