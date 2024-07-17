#include "../push_swap.h"

void	finish_rotation(t_stack **stack,
							t_stack *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->half == ABOVE)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->half == ABOVE)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

t_stack *get_cheapest(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if(b->cheapest == TRUE)
			return(b);
		b = b->next;
	}
	return(NULL);
}

static void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_pos_half(*a);
	set_pos_half(*b);
} 

static void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_pos_half(*a);
	set_pos_half(*b);
} 

static void moving (t_stack **a, t_stack **b)
{
	t_stack *cheapest;
	
	cheapest = get_cheapest(*b);
	// ft_printf("cheapest:%d\n\n\n\n", cheapest->number);
	if(cheapest->half == ABOVE && cheapest->target->half == ABOVE)
		rotate_both(a, b, cheapest);
	else if (cheapest->half == BELOW && cheapest->target->half == BELOW)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b);
}

void push_swap(t_stack **a, t_stack **b)
{
	int len;
	t_stack *smallest;

	len = ft_stacksize(*a);
	while (len-- > 3)
			pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_values(*a, *b);
		moving(a, b);
	}
	set_pos_half(*a);
	smallest = find_the_small_one(*a);
	if(smallest->half == ABOVE)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}