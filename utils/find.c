#include"../push_swap.h"

t_stack *find_the_big_one(t_stack *stack)
{
	int highest;
	t_stack *highest_node;

	highest = INT_MIN;
	while (stack)
	{
		if(stack->number > highest)
		{
			highest = stack->number;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return(highest_node);
}

t_stack *find_the_small_one(t_stack *stack)
{
	int smallest;
	t_stack *smallest_node;

	smallest = INT_MAX;
	while (stack)
	{
		if(stack->number < smallest)
		{
			smallest = stack->number;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return(smallest_node);
}

void find_the_small_price(t_stack *stack)
{
	int smallest;
	t_stack *smallest_node;

	smallest = INT_MAX;
	while (stack)
	{
		if(stack->price < smallest)
		{
			smallest = stack->price;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	smallest_node->cheapest = TRUE;
}