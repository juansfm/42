/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:26:50 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/02 11:00:52 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(const char *str, char c);
static char	**alloc_matrix(const char *s1, int num_words, char c);

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		num_lines;
	char	**matrix;

	i = 0;
	num_lines = num_words(s, c);
	matrix = alloc_matrix(s, num_lines, c);
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
		if (i == num_lines +2)
			break ;
		while (s[k] == c)
			k++;
		matrix[i][j] = s[k];
		k++;
		j++;
	}
	return (matrix);
}

static int	num_words(const char *s1, char c)
{
	int		i;
	int		num;
	char	*s2;

	s2 = ft_strtrim(s1, &c);
	num = 0;
	i = 0;
	while (s1[i])
	{
		if (i == 0 && s1[i] == c)
			i++;
		if (s1[i] == c && s1[i + 1] != c && s1[i + 1] != '\0')
			num++;
		i++;
	}
	return (num);
}

static char	**alloc_matrix(const char *s1, int num_words, char c)
{
	int		i;
	int		j;
	int		k;
	char	*s2;
	char	**matrix;

	i = 0;
	j = 0;
	k = 0;
	matrix = (char **)ft_calloc((num_words), sizeof(char *));
	if (matrix == NULL)
		return (0);
	s2 = ft_strtrim(s1, &c);
	while (i < num_words)
	{
		if (s2[i] == c)
		{
			matrix[k] = (char *)ft_calloc((j +1), sizeof(char));
			if (matrix[k] == NULL)
				return (0);
			j = -1;
			k++;
		}
		i++;
		j++;
	}
	return (matrix);
}
