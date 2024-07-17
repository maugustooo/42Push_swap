#include "../push_swap.h"

void set_pos_half(t_stack *stack)
{
	int i;
	int half;

	half = ft_stacksize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->current_pos = i;
		if(i <= half)
			stack->half = ABOVE;
		else
			stack->half = BELOW;
		stack = stack->next;
		++i;
	}
	
}
static void set_target(t_stack *a, t_stack *b)
{
	int best_value;
	t_stack *target_node;
	t_stack *current;

	while (b)
	{
		best_value = INT_MAX;
		current = a;
		while (current)
		{
			if(current->number > b->number && current->number < best_value)
			{
				best_value = current->number;
				target_node = current;
			}
			current = current->next;
		}
		if(best_value == INT_MAX)
			b->target = find_the_small_one(a);
		else 
			b->target = target_node;
		b = b->next;
	}
	
}
static void set_price(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	while (b)
	{
		b->price = b->current_pos;
		if(b->half == BELOW)
			b->price = len_b - (b->current_pos);
		if(b->target->half == ABOVE)
			b->price += b->target->current_pos;
		else
			b->price += len_a - (b->target->current_pos);
		b = b->next;
	}
}
void set_values(t_stack *a, t_stack *b)
{
	set_pos_half(a);
	set_pos_half(b);
	set_target(a, b);
	set_price(a, b);
	find_the_small_price(b);
}