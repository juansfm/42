/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:35:51 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/31 13:45:21 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char **argv)
{
	int		error;
	char	*ext;

	error = 0;
	if (argc != 2)
		error = 1;
	if (argc == 1)
		ft_putstr_fd("Error\nNo arguments\n", 2);
	if (argc > 2)
		ft_putstr_fd("Error\nToo many arguments\n", 2);
	ext = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strncmp(ext, ".ber", 4) != 0 && argc == 2)
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		error = 1;
	}
	return (free(ext), error);
}

int	ft_check(t_game *map)
{
	int	error;

	error = ft_check_map(map);
	if (error > 0)
		return (error);
	error = 0;
	error = ft_check_chars(map, error);
	if (error > 0)
		return (error);
	error = ft_check_path(map);
	if (error > 0)
		ft_putstr_fd("Error\nInvalid path\n", 2);
	return (error);
}

int	ft_check_map(t_game *map)
{
	int	error;
	int	i;
	int	j;
	int	col;

	error = 0;
	i = -1;
	while (++i < map->rows)
	{
		col = ft_strlen(map->map[i]);
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
			col = ft_strlen(map->map[i]) - 1;
		if (col != map->cols)
			error++;
		j = -1;
		while (++j < map->cols)
			if (((i == 0 || i == map->rows - 1) || j == 0 || j == map->cols - 1)
				&& (map->map[i][j] != '1'))
				error++;
	}
	if (error > 0)
		ft_putstr_fd("Error\nMap isn't rectangular", 2);
	return (error);
}

int	ft_check_chars(t_game *map, int error)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == 'E')
				map->exit_flag++;
			else if (map->map[i][j] == 'C')
				map->collect_flag++;
			else if (map->map[i][j] == 'P')
				map->player_flag++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				error++;
		}
	}
	if (map->exit_flag != 1 || map->player_flag != 1 || map->collect_flag <= 0)
		error++;
	if (error > 0)
		ft_putstr_fd("Error\nIncorrect map configuration\n", 2);
	return (error);
}

int	ft_check_path(t_game *map)
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
				break ;
			}
		}
	}
	copy = ft_copy(map->map);
	copy = ft_flood_fill(copy, coord[0], coord[1]);
	error = ft_flood_check(copy);
	return (error);
}
