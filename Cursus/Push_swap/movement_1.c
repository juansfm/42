/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:07:34 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/03/31 14:16:30 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int pos, t_stack *stack)
{
	t_stack	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (pos == 'a' || pos == 'b')
	{
		write(1, "s", 1);
		write(1, &pos, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(int pos, t_stack *stack)
{
	t_stack	temp;
	int		p;

	p = 0;
	temp = stack[0];
	while (p < stack[0].now_elements - 1)
	{
		stack[p] = stack[p + 1];
		p++;
	}
	stack[p] = temp;
	if (pos == 'a' || pos == 'b')
	{
		write(1, "r", 1);
		write(1, &pos, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse(int pos, t_stack *stack)
{
	t_stack	temp;
	int		p;

	p = stack[0].now_elements - 1;
	temp = stack[p];
	while (p > 0)
	{
		stack[p] = stack[p - 1];
		p--;
	}
	stack[0] = temp;
	if (pos == 'a' || pos == 'b')
	{
		write(1, "rr", 2);
		write(1, &pos, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(int pos, t_stack *stack_i, t_stack *stack_f)
{
	t_stack	temp;
	int		p;

	temp = stack_i[0];
	p = -1;
	while (++p < stack_i[0].now_elements - 1)
		stack_i[p] = stack_i[p + 1];
	p = stack_f[0].now_elements + 1;
	while (--p > 0)
		stack_f[p] = stack_f[p - 1];
	stack_f[0] = temp;
	ft_push_update(stack_i, stack_f);
	if (pos == 'a' || pos == 'b')
	{
		write(1, "p", 1);
		write(1, &pos, 1);
		write(1, "\n", 1);
	}
}

void	ft_doble_mov(char *pos, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(pos, "ss", ft_strlen(pos)))
	{
		write(1, "ss", 2);
		ft_swap('c', stack_a);
		ft_swap('c', stack_b);
	}
	if (ft_strncmp(pos, "rr", ft_strlen(pos)))
	{
		write(1, "rr", 2);
		ft_rotate('c', stack_a);
		ft_rotate('c', stack_b);
	}
	if (ft_strncmp(pos, "rrr", ft_strlen(pos)))
	{
		write(1, "rrr", 2);
		ft_reverse('c', stack_a);
		ft_reverse('c', stack_b);
	}
}
