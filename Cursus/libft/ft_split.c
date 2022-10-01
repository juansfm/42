/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:26:50 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/29 17:13:09 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(const char *str, char c);

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		num_lines;
	char	**matrix;

	i = 0;
	num_lines = num_words(s, c);
	matrix = (char **)ft_calloc((num_lines), sizeof(char *));
	if (matrix == NULL)
		return (0);
	i = 0;
	while ((size_t)i < (ft_strlen(s) + 1))
	{
		matrix[i] = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
		if (matrix[i] == NULL)
			return (0);
		i++;
	}
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

static int	num_words(const char *str, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == c)
			i++;
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			num++;
		i++;
	}
	return (num);
}
