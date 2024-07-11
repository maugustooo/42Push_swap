#include "../push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
	t_stack *node;

	node = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	node -> next = NULL;
	if(*dest == NULL)
	{
		*dest = node;
		node -> next = NULL;
	}
	else
	{
		node ->next = *dest;
		node ->next->prev = NULL;
		*dest = node;
	}
}

void pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}