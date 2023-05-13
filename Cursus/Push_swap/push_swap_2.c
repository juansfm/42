/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:52:32 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 17:49:37 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_update(t_stack *stack_i, t_stack *stack_f)
{
	int	p;

	p = 0;
	stack_i[0].now_elem--;
	while (++p < stack_i[0].now_elem)
	{
		stack_i[p].now_elem--;
		stack_i[p].pos = p;
	}
	p = stack_f[1].now_elem + 1;
	while (--p >= 0)
	{
		stack_f[p].now_elem++;
		stack_f[p].pos = p;
	}
	stack_f[0].now_elem = stack_f[1].now_elem;
	if (stack_f[0].now_elem == 0)
		stack_f[0].now_elem = 1;
}

void	ft_3_params(t_stack *stack)
{
	if (stack[0].num > stack[1].num && stack[0].num < stack[2].num)
		ft_swap('a', stack);
	else if (stack[0].num > stack[1].num && stack[1].num > stack[2].num)
	{
		ft_rotate('a', stack);
		ft_swap('a', stack);
	}
	else if (stack[0].num < stack[2].num && stack[1].num > stack[2].num)
	{
		ft_swap('a', stack);
		ft_rotate('a', stack);
	}
	else if (stack[0].num > stack[2].num && stack[1].num < stack[2].num)
		ft_rotate('a', stack);
	else if (stack[0].num < stack[1].num && stack[0].num > stack[2].num)
		ft_reverse('a', stack);
}

void	ft_more_than_3_params(t_stack *stack_a, t_stack *stack_b)
{
	int		media;
	t_stack	temp;

	ft_push_to_3_params(stack_a, stack_b);
	ft_3_params(stack_a);
	while (stack_a[0].now_elem < stack_a[0].total_elements)
	{
		ft_target(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		temp = ft_min_cost(stack_b);
		ft_move_min(stack_a, stack_b, temp);
		ft_push('a', stack_b, stack_a);
	}
	media = stack_a[0].total_elements / 2;
	while (stack_a[0].index != 1)
	{
		if (stack_a[0].index > media)
			ft_rotate('a', stack_a);
		else
			ft_reverse('a', stack_a);
	}
}

void	ft_put_index(t_stack *stack)
{
	int	min;
	int	i;
	int	j;

	i = -1;
	while (++i < stack[0].total_elements)
	{
		min = ft_min(stack);
		j = -1;
		while (++j < stack[0].total_elements)
			if (stack[j].num == min)
				stack[j].index = i + 1;
	}
}

int	ft_min(t_stack *stack)
{
	int	min;
	int	i;

	min = 2147483647;
	i = -1;
	while (++i < stack[0].total_elements)
		if (stack[i].num < min && stack[i].index == -1)
			min = stack[i].num;
	return (min);
}
