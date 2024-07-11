#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
# define TRUE 1
# define FALSE 0
# define ABOVE 2
# define BELOW 3


typedef struct s_stack
{
	int				number;
	int				current_pos;
	int				price;
	int				half;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int error();
int handle_errors(char *argv, long nbr, t_stack **a);
int repeat_nbr( t_stack *a, int nbr);

t_stack	*ft_stacknew(int nbr);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int	ft_stacksize(t_stack *stack);

void find_the_small_price(t_stack *stack);
t_stack *find_the_big_one(t_stack *stack);
t_stack *find_the_small_one(t_stack *stack);


void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);


void push_swap(t_stack **a, t_stack **b);

void set_values(t_stack **a, t_stack **b);

static void sort_three(t_stack **a);
#endif