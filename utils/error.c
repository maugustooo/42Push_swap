#include "../push_swap.h"

int handle_errors(char *argv, long nbr, t_stack **a)
{
	int i;
	int result;

	result = TRUE;
	i = 0;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return(FALSE);
	if(repeat_nbr(*a, nbr) == 0)
		return(FALSE);
	if (argv[0] != '+' && argv[0] != '-' && argv[0] >= '0' && argv[0] <= '9')
		result = TRUE;
	if ((argv[0] == '+' || argv[0] == '-') && argv[1] >= '0' && argv[1] <= '9')
	{
		i++;
		result = TRUE;
	}
	while (argv[i])
	{
		if(!ft_isdigit(argv[i]))
			return(FALSE);
		i++;
	}
	return(result);
}

int repeat_nbr( t_stack *a, int nbr)
{
	while (a)
	{
		if(a->number == nbr)
			return(0);
		a = a->next;
	}
	return(1);
}

int error()
{
	ft_printf("Error\n");
	exit(0);
}