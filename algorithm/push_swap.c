#include "../push_swap.h"

void sort_2_or_3(t_stack **a)
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

static int sorted(t_stack *stack)
{
	while (stack->next)
	{
		ft_printf("%d", stack->number);
		if(stack->number > stack->next->number)
			return(FALSE);
		stack = stack->next;
	}
	if(ft_stacksize(stack) == 2)
		sa(&stack);
	else if (ft_stacksize(stack) == 3)
		sort_three(&stack);
	return(TRUE);
}

static void rotate_until_top(t_stack **a, t_stack **b, t_stack *top_a,
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

	if(sorted(a))
		return ;
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
