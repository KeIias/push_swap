#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

void	swap(t_dlist **beg);
void	push(t_dlist **from, t_dlist **to);
void	rotate(t_dlist **beg);
void	reverse_rotate(t_dlist **beg);

#endif
