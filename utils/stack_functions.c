#include "../push_swap.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->number = nbr;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack && new)
	{
		if (*stack)
		{
			last = ft_stacklast(*stack);
			last->next = new;
			new->prev = last;
		}
		else
			*stack = new;
	}
}
int	ft_stacksize(t_stack *stack)
{
	t_stack	*node;
	int		i;

	node = stack;
	i = 0;
	while (node)
	{
		i++;
		node = node -> next;
	}
	return (i);
}