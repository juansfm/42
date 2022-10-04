/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:26:50 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/04 20:04:11 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char *str, char c);
static char	**alloc_matrix(char *s1, int num_words, char **matrix, char c);
static void	fill_words(char *s, char **matrix, int num_words, char c);

char	**ft_split(const char *s, char c)
{
	int		num_lines;
	char	*str;
	char	**matrix;

	str = ft_strtrim(s, &c);
	if (str == NULL)
		return (0);
	num_lines = num_words(str, c);
	matrix = (char **)ft_calloc(num_lines + 1, sizeof(char *));
	if (matrix == NULL)
		return (0);
	matrix = alloc_matrix(str, num_lines, matrix, c);
	fill_words(str, matrix, num_lines, c);
	free(str);
	return (matrix);
}

static int	num_words(char *s1, char c)
{
	int		i;
	int		num;

	num = 1;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c && s1[i +1] != c)
			num++;
		i++;
	}
	return (num);
}

static char	**alloc_matrix(char *s1, int num_words, char **matrix, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (k < num_words)
	{
		while (s1[i] == c)
			i++;
		j = 0;
		while (s1[i] != c && s1[i] != '\0')
		{
			j++;
			i++;
		}
		matrix[k] = (char *)ft_calloc(j + 1, sizeof(char));
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
	k = 0;
	while (s[k] && i < num_words)
	{
		j = 0;
		while (s[k] != c && s[k] != '\0')
		{
			matrix[i][j] = s[k];
			k++;
			j++;
		}
		if (s[k] == c && s[k +1] != c)
		{
			i++;
		}
		k++;
	}
}

//hacer free si da fallos en una fila