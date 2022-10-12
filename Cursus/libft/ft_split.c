/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:26:50 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/12 11:42:42 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_words(char *str, char c);
static char	**ft_alloc_matrix(char *s1, int num_words, char **matrix, char c);
static void	ft_fill_words(char *s, char **matrix, int num_words, char c);
static void	ft_free(char **matrix);

char	**ft_split(const char *s, char c)
{
	int		num_lines;
	char	*str;
	char	**matrix;

	str = ft_strtrim(s, &c);
	if (str == NULL)
		return (NULL);
	num_lines = ft_num_words(str, c);
	matrix = (char **)ft_calloc(num_lines + 1, sizeof(char *));
	if (matrix == NULL)
		return (free(str), NULL);
	matrix = ft_alloc_matrix(str, num_lines, matrix, c);
	ft_fill_words(str, matrix, num_lines, c);
	free(str);
	return (matrix);
}

static int	ft_num_words(char *s1, char c)
{
	size_t	i;
	int		num;

	if (ft_strlen(s1) == 0)
		return (0);
	num = 1;
	i = 0;
	while (i < ft_strlen(s1))
	{
		if (s1[i] == c && s1[i + 1] != c)
			num++;
		i++;
	}
	return (num);
}

static char	**ft_alloc_matrix(char *s1, int num_words, char **matrix, char c)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (k < num_words)
	{
		while (s1[i] == c && i <= ft_strlen(s1))
			i++;
		j = 0;
		while (s1[i] != c && i <= ft_strlen(s1))
		{
			j++;
			i++;
		}
		matrix[k] = (char *)ft_calloc(j + 1, sizeof(char));
		if (matrix[k] == NULL)
			return (ft_free(matrix), NULL);
		k++;
		i++;
	}
	return (matrix);
}

static void	ft_fill_words(char *s, char **matrix, int num_words, char c)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (k < ft_strlen(s) && i < num_words)
	{
		j = 0;
		while (s[k] != c && k < ft_strlen(s))
		{
			matrix[i][j] = s[k];
			k++;
			j++;
		}
		if (s[k] == c && s[k + 1] != c)
			i++;
		k++;
	}
}

static void	ft_free(char **matrix)
{
	int	k;

	k = 0;
	while (matrix[k])
		free(matrix[k++]);
	free(matrix);
}
