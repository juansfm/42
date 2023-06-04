/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:47:40 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/30 13:20:02 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_flood_fill(char **map, int x, int y)
{
	if (map[x + 1][y] != '1' && map[x + 1][y] != 'F')
	{
		map[x + 1][y] = 'F';
		map = ft_flood_fill(map, x + 1, y);
	}
	if (map[x - 1][y] != '1' && map[x - 1][y] != 'F')
	{
		map[x - 1][y] = 'F';
		map = ft_flood_fill(map, x - 1, y);
	}
	if (map[x][y + 1] != '1' && map[x][y + 1] != 'F')
	{
		map[x][y + 1] = 'F';
		map = ft_flood_fill(map, x, y + 1);
	}
	if (map[x][y - 1] != '1' && map[x][y - 1] != 'F')
	{
		map[x][y - 1] = 'F';
		map = ft_flood_fill(map, x, y - 1);
	}
	return (map);
}

char	**ft_copy(char **map)
{
	size_t	i;
	char	**copy;
	size_t	row;

	row = ft_strlen(*map);
	copy = ft_calloc(row, sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(*map) - 1)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_flood_check(char **map)
{
	size_t	i;
	size_t	j;
	int		error;

	error = 0;
	i = -1;
	while (++i < ft_strlen(*map))
	{
		j = -1;
		while (++j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				error++;
		}
	}
	return (error);
}
