/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:59:07 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 17:50:10 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
num = number
index = position when stack a is sorted
pos = position in the stack
target_pos = target position in the stack_a for numbers of stack_b
cost_a = cost to move the number to its position in stack_a
cost_b = cost to move the number to the top of stack_b
total_cost = cost_a + cost_b
now_elem = number of elements in the stack in that moment
total_elements = total number of elements
*/
typedef struct s_stack
{
	int	num;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	now_elem;
	int	total_elements;
}		t_stack;

//LIBFT UTILS
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_num_words(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//PUSH SWAP
int		ft_main_conditions(int *n_count, char **argv, int **numbers);
int		ft_check_error(char **av, int *numbers, int error, int split);
t_stack	*ft_create_stack(t_stack *stack, int *numbers, int n_count);
int		ft_ord(int *numbers, int ord);
void	ft_3_params(t_stack *stack);
void	ft_more_than_3_params(t_stack *stack_a, t_stack *stack_b);
void	ft_push_to_3_params(t_stack *stack_a, t_stack *stack_b);
void	ft_push_update(t_stack *stack_i, t_stack *stack_f);
void	ft_put_index(t_stack *stack);
int		ft_min(t_stack *stack);
void	ft_target(t_stack *stack_a, t_stack *stack_b);
void	ft_cost(t_stack *stack_a, t_stack *stack_b);
void	ft_total_cost(t_stack *stack_b);
t_stack	ft_min_cost(t_stack *stack);
void	ft_move_min(t_stack *stack_a, t_stack *stack_b, t_stack temp);
void	ft_final_rotate(t_stack *stack_a, t_stack *stack_b, t_stack temp);

//MOVES
void	ft_swap(int pos, t_stack *stack);
void	ft_rotate(int pos, t_stack *stack);
void	ft_reverse(int pos, t_stack *stack);
void	ft_push(int pos, t_stack *stack_a, t_stack *stack_b);
void	ft_doble_mov(char *pos, t_stack *stack_a, t_stack *stack_b);
#endif