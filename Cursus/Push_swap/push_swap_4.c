/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:42:16 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 17:50:04 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_min(t_stack *stack_a, t_stack *stack_b, t_stack temp)
{
	while (temp.cost_a > 0 && temp.cost_b > 0 && temp.total_cost != 0)
	{
		ft_doble_mov("rro", stack_a, stack_b);
		temp.cost_a--;
		temp.cost_b--;
		temp.total_cost--;
	}
	while (temp.cost_a < 0 && temp.cost_b < 0 && temp.total_cost != 0)
	{
		ft_doble_mov("rrr", stack_a, stack_b);
		temp.cost_a++;
		temp.cost_b++;
		temp.total_cost--;
	}
	ft_final_rotate(stack_a, stack_b, temp);
}

void	ft_final_rotate(t_stack *stack_a, t_stack *stack_b, t_stack temp)
{
	while (temp.cost_a != 0 || temp.cost_b != 0)
	{
		if (temp.cost_a > 0)
		{
			ft_rotate('a', stack_a);
			temp.cost_a--;
		}
		else if (temp.cost_a < 0)
		{
			ft_reverse('a', stack_a);
			temp.cost_a++;
		}
		if (temp.cost_b > 0)
		{
			ft_rotate('b', stack_b);
			temp.cost_b--;
		}
		else if (temp.cost_b < 0)
		{
			ft_reverse('b', stack_b);
			temp.cost_b++;
		}
	}
}
