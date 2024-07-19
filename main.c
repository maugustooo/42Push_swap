/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:59:30 by maugusto          #+#    #+#             */
/*   Updated: 2024/07/19 15:11:46 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(char **argv, t_stack **a, int argc)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (!handle_errors(argv[i], nbr, a))
			exit_program(a, argc, argv, 1);
		ft_stackadd_back(a, ft_newnode(nbr));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	fill_stack(args, &a, argc);
	push_swap(&a, &b);
	exit_program(&a, argc, args, 0);
}
