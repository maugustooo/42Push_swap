#include "../push_swap.h"

void sort_three(t_stack **a)
{
	t_stack *the_big_one;

	the_big_one = find_the_big_one(*a);
	if(*a == the_big_one)
		ra(a);
	else if ((*a)->next == the_big_one)
		rra(a);
	if((*a)->number > (*a)->next->number)
		sa(a);
}
