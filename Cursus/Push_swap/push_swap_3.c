/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:01:33 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 17:49:52 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_3_params(t_stack *stack_a, t_stack *stack_b)
{
	ft_put_index(stack_a);
	while (stack_a[0].now_elem > 3)
	{
		if (stack_a[0].index <= 3)
			ft_rotate('a', stack_a);
		if (stack_a[0].index > 3)
			ft_push('b', stack_a, stack_b);
	}
}

void	ft_target(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < stack_b[0].now_elem)
	{
		j = -1;
		aux = 0;
		while (++j < stack_a[0].now_elem)
		{
			if (stack_b[i].index < stack_a[j].index && aux > stack_a[j].index)
			{
				aux = stack_a[j].index;
				stack_b[i].target_pos = stack_a[j].pos;
			}
			else if (stack_b[i].index >= stack_a[j].index
				&& aux < stack_a[j].index)
			{
				aux = stack_a[j].index;
				stack_b[i].target_pos = stack_a[j].pos + 1;
			}
		}
	}
}

void	ft_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	media;

	media = stack_b[0].now_elem / 2;
	i = -1;
	while (++i < stack_b[0].now_elem)
	{
		if (stack_b[i].pos <= media)
			stack_b[i].cost_b = i;
		else
			stack_b[i].cost_b = stack_b[i].pos - stack_b[i].now_elem;
	}
	media = (stack_a[0].now_elem + 1) / 2;
	i = -1;
	while (++i < stack_b[0].now_elem)
	{
		if (stack_b[i].target_pos <= media)
			stack_b[i].cost_a = stack_b[i].target_pos;
		else
			stack_b[i].cost_a = stack_b[i].target_pos - stack_a[0].now_elem;
	}
	ft_total_cost(stack_b);
}

void	ft_total_cost(t_stack *stack_b)
{
	int	i;

	i = -1;
	while (++i < stack_b[0].now_elem)
	{
		stack_b[i].total_cost = 0;
		if (stack_b[i].cost_a > 0)
			stack_b[i].total_cost += stack_b[i].cost_a;
		else
			stack_b[i].total_cost -= stack_b[i].cost_a;
		if (stack_b[i].cost_b > 0)
			stack_b[i].total_cost += stack_b[i].cost_b;
		else
			stack_b[i].total_cost -= stack_b[i].cost_b;
	}
}

t_stack	ft_min_cost(t_stack *stack)
{
	int		i;
	t_stack	min;

	i = -1;
	min.total_cost = stack[0].total_cost;
	while (++i < stack[0].now_elem)
	{
		if (stack[i].total_cost <= min.total_cost)
			min = stack[i];
	}
	return (min);
}
