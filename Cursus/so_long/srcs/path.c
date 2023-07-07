/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:47:40 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 13:31:00 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_game *map)
{
	char	**copy;
	int		coord[2];
	int		i;
	int		j;
	int		error;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				coord[0] = i;
				coord[1] = j;
			}
		}
	}
	copy = ft_copy(map->map);
	copy = ft_flood_fill(copy, coord[0], coord[1]);
	error = ft_flood_check(copy);
	ft_free(copy);
	if (error > 0)
		ft_error('P', map);
}

char	**ft_copy(char **map)
{
	size_t	i;
	char	**copy;
	size_t	row;

	row = 0;
	i = -1;
	while (map[++i])
		row++;
	copy = ft_calloc(row + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
	}
	copy[i] = NULL;
	return (copy);
}

char	**ft_flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return (map);
	map[x][y] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
	return (map);
}

int	ft_flood_check(char **map)
{
	size_t	i;
	size_t	j;
	int		error;
	size_t	row;

	error = 0;
	i = -1;
	row = 0;
	while (map[++i])
		row++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				error++;
		}
	}
	return (error);
}
