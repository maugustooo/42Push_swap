#include "push_swap.h"

static int sorted(t_stack *stack)
{
	while (stack->next)
	{
		ft_printf("%d", stack->number);
		if(stack->number > stack->next->number)
			return(FALSE);
		stack = stack->next;
	}
	return(TRUE);
}

static void fill_stack(char **argv, t_stack **a)
{
    int i;
	long nbr;

    i = 0;
    while (argv[i])
    {
		nbr = ft_atol(argv[i]);
		if(!handle_errors(argv[i], nbr, a))
			error();
		ft_stackadd_back(a, ft_stacknew(nbr));
        i++;
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
	char	**args;

	a = NULL;
	b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 0;
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
    fill_stack(args, &a);
	t_stack *current = a;
  	printf("\n\nA\n");
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }
	if(!sorted(a))
	{
		if(ft_stacksize(a) == 2)
			sa(&a);
		else if (ft_stacksize(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	current = a;
  	printf("\n\nA\n");
    while (current != NULL) 
	{
        printf("%d\n", current->number);
        current = current->next;
    }
}
