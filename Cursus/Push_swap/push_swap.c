/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:59:12 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 19:05:49 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	numbers = malloc(sizeof(int) * --argc);
	if (!numbers)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_main_conditions(&argc, argv, &numbers))
	{
		stack_a = ft_create_stack(stack_a, numbers, argc);
		stack_b = ft_create_stack(stack_b, NULL, argc);
	}
	if (!stack_a || !stack_b)
		return (free(numbers), free(stack_a), free(stack_b), 0);
	if (argc == 2 && ft_ord(numbers, argc))
		ft_swap('a', stack_a);
	else if (argc == 3 && ft_ord(numbers, argc))
		ft_3_params(stack_a);
	else if (argc > 3 && ft_ord(numbers, argc))
		ft_more_than_3_params(stack_a, stack_b);
	return (free(numbers), free(stack_a), free(stack_b), 0);
}

int	ft_main_conditions(int *n_count, char **argv, int **numbers)
{
	int	error;
	int	split;

	split = 1;
	if (n_count[0] == 1)
	{
		n_count[0] = ft_num_words(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		free(numbers[0]);
		if (!argv)
			return (0);
		numbers[0] = malloc(sizeof(int) * n_count[0]);
		if (!numbers[0])
			return (0);
		split = 0;
	}
	error = 0;
	error = ft_check_error(argv, numbers[0], error, split);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (!error);
}

t_stack	*ft_create_stack(t_stack *stack, int *numbers, int n_count)
{
	int	i;

	stack = malloc(sizeof(*stack) * n_count);
	if (!stack)
		return (NULL);
	i = -1;
	while (++i < n_count)
	{
		if (numbers != NULL)
		{
			stack[i].num = numbers[i];
			stack[i].pos = i;
			stack[i].now_elem = n_count;
		}
		else if (numbers == NULL)
		{
			stack[i].pos = -1;
			stack[i].target_pos = -1;
			stack[i].now_elem = 0;
		}
		stack[i].index = -1;
		stack[i].total_elements = n_count;
	}
	return (stack);
}

int	ft_check_error(char **av, int *numbers, int error, int split)
{
	int	i;
	int	j;

	i = -1 + split;
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
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			error = 1;
		numbers[i - split] = ft_atoi(av[i]);
		if (!split)
			free(av[i]);
	}
	if (ft_ord(numbers, i - split) == 2)
		error = 1;
	if (!split)
		free(av);
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
	if (dup != 0)
		return (2);
	if (ord == 0)
		return (0);
	return (1);
}
