/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:35:51 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 15:38:09 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		ft_error('A', NULL);
	ext = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strncmp(ext, ".ber", 4) != 0 && argc == 2)
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		exit(1);
	}
	free(ext);
}

void	ft_check_map(t_game *map)
{
	int	i;
	int	j;
	int	col;

	i = -1;
	while (++i < map->rows)
	{
		col = ft_strlen(map->map[i]);
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
			col = ft_strlen(map->map[i]) - 1;
		if (col != map->cols)
			ft_error('M', map);
		j = -1;
		while (++j < map->cols)
			if (((i == 0 || i == map->rows - 1) || j == 0 || j == map->cols - 1)
				&& (map->map[i][j] != '1'))
				ft_error('W', map);
	}
}

void	ft_check_chars(t_game *map)
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
				ft_error('C', map);
		}
	}
	if (map->exit_flag != 1 || map->player_flag != 1 || map->collect_flag <= 0)
		ft_error('C', map);
}

void	ft_error(char error, t_game *game)
{
	if (error == 'C')
		ft_putstr_fd("Error\nInvalid configuration of characters\n", 2);
	if (error == 'M')
		ft_putstr_fd("Error\nMap isn't rectangular\n", 2);
	if (error == 'P')
		ft_putstr_fd("Error\nInvalid path\n", 2);
	if (error == 'A')
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	if (error == 'W')
		ft_putstr_fd("Error\nMap isn't surrounded by walls\n", 2);
	if (game)
		ft_free(game->map);
	exit(1);
}
