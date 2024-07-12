#include "../push_swap.h"

void rotate_until_top(t_stack **a, t_stack **b, t_stack *top_a,
												t_stack *top_b)
{
	while (*a != top_a)
	{
		if(top_a->half == ABOVE)
			ra(a);
		else
			rra(a);
	}
	while (*b != top_b)
	{
		if(top_b->half == ABOVE)
			rb(b);
		else
			rrb(b);
	}
}

t_stack *get_cheapest(t_stack *b)
{
	while (b)
	{
		if((b->cheapest = TRUE))
			return(b);
		b = b->next;
	}
	return(NULL);
}

static void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_pos(*a);
	set_pos(*b);
} 

static void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_pos(*a);
	set_pos(*b);
} 

static void moving (t_stack **a, t_stack **b)
{
	t_stack *cheapest;

	cheapest = get_cheapest(*b);
	if(cheapest->half == ABOVE && cheapest->target->half == ABOVE)
		rotate_both(a, b, cheapest);
	else if (cheapest->half == BELOW && cheapest->target->half == BELOW)
		reverse_rotate_both(a, b, cheapest);
	rotate_until_top(a, b, cheapest->target, cheapest);
	pa(a, b);
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