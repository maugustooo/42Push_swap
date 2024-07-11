#include "../push_swap.h"

static void reverse_rotate(t_stack **stack)
{
	t_stack *last_node;

	last_node = ft_stacklast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}