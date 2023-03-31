/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:59:12 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/03/31 17:02:50 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	int		n_count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	n_count = argc - 1;
	numbers = malloc(sizeof(int) * n_count);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_main_conditions(&n_count, argv, &numbers))
	{
		stack_a = ft_create_stack(stack_a, numbers, n_count);
		stack_b = ft_create_stack(stack_b, NULL, n_count);
	}
	if (stack_a == NULL)
		return (0);
	if (n_count == 2 && ft_ord(numbers, n_count))
		ft_swap('a', stack_a);
	else if (n_count == 3 && ft_ord(numbers, n_count))
		ft_3_params(stack_a);
	else if (n_count > 3 && ft_ord(numbers, n_count))
		ft_more_than_3_params(stack_a, stack_b);
}

int	ft_main_conditions(int *n_count, char **argv, int **numbers)
{
	int	error;

	if (n_count[0] == 1)
	{
		n_count[0] = ft_num_words(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		free(numbers[0]);
		numbers[0] = malloc(sizeof(int) * n_count[0]);
	}
	error = 0;
	error = ft_check_error(argv, numbers[0], error);
	return (!error);
}

t_stack	*ft_create_stack(t_stack *stack, int *numbers, int n_count)
{
	int	i;

	stack = malloc(sizeof(*stack) * n_count);
	i = -1;
	if (numbers != NULL)
	{
		while (++i < n_count)
		{
			stack[i].num = numbers[i];
			stack[i].index = -1;
			stack[i].pos = i;
			stack[i].now_elements = n_count;
			stack[i].total_elements = n_count;
		}
	}
	else if (numbers == NULL)
	{
		while (++i < n_count)
		{
			stack[i].pos = -1;
			stack[i].now_elements = 0;
			stack[i].total_elements = n_count;
		}
	}
	return (stack);
}

int	ft_check_error(char **av, int *numbers, int error)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		while (av[i][++j] != '\0')
		{
			if (((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-'
					&& av[i][j] != '+') || ((av[i][j] == '-' || av[i][j] == '+')
					&& (av[i][j + 1] < '0' || av[i][j + 1] > '9')))
				error = 1;
		}
		numbers[i - 1] = ft_atoi(av[i]);
	}
	return (error);
}

int	ft_ord(int *numbers, int count)
{
	int	i;
	int	j;
	int	ord;
	int	dup;

	ord = 0;
	dup = 0;
	i = -1;
	while (++i < count)
	{
		j = i;
		while (++j < count)
		{
			if (numbers[i] > numbers[j])
				ord++;
			if (numbers[i] == numbers[j])
				dup++;
		}
	}
	if (ord == 0 || dup != 0)
		return (0);
	return (1);
}
