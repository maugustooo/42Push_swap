/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:58:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/07/23 11:12:27 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack **a)
{
	t_stack	*the_big_one;

	the_big_one = find_the_big_one(*a);
	if (*a == the_big_one)
		ra(a);
	else if ((*a)->next == the_big_one)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

static int	sorted(t_stack **stack)
{
	t_stack	*current;
	int		flag;

	flag = 1;
	current = *stack;
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			flag = 0;
			break ;
		}
		current = current->next;
	}
	if (ft_stacksize(*stack) == 2 && !flag)
	{
		sa(stack);
		return (TRUE);
	}
	else if (ft_stacksize(*stack) == 3 && !flag)
	{
		sort_three(stack);
		return (TRUE);
	}
	return (flag);
}

static void	rotate_until_top(t_stack **a, t_stack **b, t_stack *top_a,
														t_stack *top_b)
{
	while (*a != top_a)
	{
		if (top_a->half == ABOVE)
			ra(a);
		else
			rra(a);
	}
	while (*b != top_b)
	{
		if (top_b->half == ABOVE)
			rb(b);
		else
			rrb(b);
	}
}

static void	moving(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b);
	if (cheapest->half == ABOVE && cheapest->target->half == ABOVE)
		rotate_both(a, b, cheapest);
	else if (cheapest->half == BELOW && cheapest->target->half == BELOW)
		reverse_rotate_both(a, b, cheapest);
	rotate_until_top(a, b, cheapest->target, cheapest);
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*the_small_one;

	if (sorted(a))
		return ;
	len = ft_stacksize(*a);
	while (len-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_values(a, b);
		moving(a, b);
	}
	set_pos(*a);
	the_small_one = find_the_small_one(*a);
	if (the_small_one->half == ABOVE)
		while (*a != the_small_one)
			ra(a);
	else
		while (*a != the_small_one)
			rra(a);
}
