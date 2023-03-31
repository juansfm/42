/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:52:32 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/03/31 17:24:42 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_update(t_stack *stack_i, t_stack *stack_f)
{
	int	p;

	p = -1;
	while (++p < stack_f[0].now_elements + 1)
	{
		stack_i[p].now_elements--;
		stack_i[p].pos = p;
	}
	p = stack_f[0].now_elements;
	while (--p > 0)
	{
		stack_f[p].now_elements++;
		stack_f[p].pos = p;
	}
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
	int	media;

	ft_put_index(stack_a);
	media = stack_a[0].total_elements / 2;
	if (media < 3)
		media = 3;
	while (stack_a[0].now_elements > media * 2)
	{
		if (stack_a[0].index >= media)
			ft_push('b', stack_a, stack_b);
		else
			ft_rotate('a', stack_a);
	}
	while (stack_a[0].now_elements > 3)
		ft_push('b', stack_a, stack_b);
	ft_3_params(stack_a);
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
				stack[j].index = i;
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
