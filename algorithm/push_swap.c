#include "../push_swap.h"

// void rotating(t_stack **stack, t_stack *smallest)
// {
// 	while (*stack != smallest)
// 	{
// 		if((*stack)->half == ABOVE)
// 			ra(stack);
// 		else
// 			rra(stack);
// 	}
	
// }

// void five_case(t_stack **a, t_stack **b)
// {
// 	while (ft_stacksize(*a) > 3)
// 	{
// 		set_values(a, b);
// 		rotating(a, find_the_small_one(*a));
// 		pb(a, b);
// 	}
// }

t_stack *get_cheapest(t_stack *b)
{
	t_stack *cheapest_node;

	cheapest_node = b;
	while (b)
	{
		if(b->cheapest = TRUE)
		{
			cheapest_node = b;
			return(cheapest_node);
		}
		b = b->next;
	}
	
}

static void moving (t_stack **a, t_stack **b)
{
	t_stack *cheapest;

	cheapest = get_cheapest(*b);
}
void push_swap(t_stack **a, t_stack **b)
{
	int len;

	len = ft_stacksize(*a);
	while (len -- > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_values(a, b);
		moving(a, b);
	}
}