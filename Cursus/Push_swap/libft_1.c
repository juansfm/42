/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:54:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/04/26 15:51:54 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size_word(const char *str, int i, char c);
static void	ft_free(char **matrix, int j);

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		num_lines;
	char	**matrix;
	int		len_word;

	i = 0;
	j = 0;
	num_lines = ft_num_words(str, c);
	matrix = malloc((num_lines + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	while (i < num_lines)
	{
		while (str[j] == c)
			j++;
		len_word = ft_size_word(str, j, c);
		matrix[i] = ft_substr(str, j, len_word);
		if (matrix[i] == NULL)
			return (ft_free(matrix, i), NULL);
		j += len_word;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	ft_num_words(const char *str, char c)

{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			num++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (num);
}

static int	ft_size_word(const char *str, int i, char c)
{
	int	size;

	size = 0;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **matrix, int j)
{
	while (j-- > 0)
		free(matrix[j]);
	free(matrix);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	return (sign * num);
}
