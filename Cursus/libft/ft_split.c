/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:26:50 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/02 19:39:53 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char *str, char c);
static char	**alloc_matrix(char *s1, int num_words, char c);
static void	fill_words(char *s, char **matrix, int num_words, char c);

char	**ft_split(const char *s, char c)
{
	int		num_lines;
	char	*str;
	char	**matrix;

	str = ft_strtrim(s, &c);
	num_lines = num_words(str, c);
	matrix = alloc_matrix(str, num_lines, c);
	fill_words(str, matrix, num_lines, c);
	free(str);
	return (matrix);
}

static int	num_words(char *s1, char c)
{
	int		i;
	int		num;

	num = 0;
	i = 0;
	while (s1[i])
	{
		while (s1[i] == c)
			i++;
		num++;
		i++;
	}
	return (num);
}

static char	**alloc_matrix(char *s1, int num_words, char c)
{
	int		i;
	int		j;
	int		k;
	char	**matrix;

	i = 0;
	k = 0;
	matrix = (char **)ft_calloc(num_words +1, sizeof(char *));
	if (matrix == NULL)
		return (0);
	while (i < num_words)
	{
		j = 0;
		while (s1[i] != c)
		{
			j++;
			i++;
		}
		matrix[k] = (char *)ft_calloc(j +1, sizeof(char));
		if (matrix[k] == NULL)
			return (0);
		k++;
		i++;
	}
	return (matrix);
}

static void	fill_words(char *s, char **matrix, int num_words, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c && i != 0)
		{
			i++;
			j = 0;
		}
		if (i == num_words +1)
			break ;
		while (s[k] == c)
			k++;
		matrix[i][j] = s[k];
		k++;
		j++;
	}
}
