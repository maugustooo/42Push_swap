/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:58:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/07/19 15:15:37 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	handle_errors(char *argv, long nbr, t_stack **a)
{
	int	i;
	int	result;

	result = TRUE;
	i = 0;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (FALSE);
	if (repeat_nbr(*a, nbr) == 0)
		return (FALSE);
	if (argv[0] != '+' && argv[0] != '-'
		&& (argv[0] >= '0' && argv[0] <= '9'))
		result = TRUE;
	if ((argv[0] == '+' || argv[0] == '-')
		&& (argv[1] >= '0' && argv[1] <= '9'))
	{
		i++;
		result = TRUE;
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (FALSE);
		i++;
	}
	return (result);
}

int	repeat_nbr(t_stack *a, int nbr)
{
	while (a)
	{
		if (a->number == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	exit_program(t_stack **a, int argc, char **argv, int error)
{
	free_stack(a);
	if (argc == 2)
		free_argv(argv);
	if (error)
		ft_printf("Error\n");
	exit(0);
}
