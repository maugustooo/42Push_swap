#include "../push_swap.h"

static void set_pos(t_stack *stack)
{
	int i;
	int half;

	half = ft_stacksize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->current_pos = i++;
		if(stack->current_pos <= half)
			stack->half = ABOVE;
		else if (stack->current_pos > half)
			stack->half = BELOW;
		stack = stack->next;
	}
	
}

static void set_target(t_stack *a, t_stack *b)
{
	int best_value;
	t_stack *target_node;

	best_value = INT_MAX;
	while (b)
	{
		while (a)
		{
			if(a->number > b->number && a->number < best_value)
			{
				target_node = a;
				best_value = b->number;
			}
			a = a->next;
		}
		if(best_value == INT_MAX)
			b->target = find_the_small_one(a);
		else 
			b->target = target_node;
		ft_printf("target do %d: %d", b->number, b->target->number);
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
			b->price = len_b - b->current_pos;
		if(b->target->half == BELOW)
			b->price += len_a - b->target->current_pos;
		else
			b->price += b->target->current_pos;
		b = b->next;
	}
}

void set_values(t_stack **a, t_stack **b)
{
	set_pos(*a);
	set_pos(*b);
	set_target(*a, *b);
	set_price(*a, *b);
	find_the_small_price(*b);
}