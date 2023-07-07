/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:36:08 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 19:54:45 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check_args(argc, argv);
	game = ft_init_game(argv[1]);
	ft_check_map(game);
	ft_check_chars(game);
	ft_check_path(game);
	ft_init_window(game);
	ft_free(game->map);
	free(game);
	return (0);
}

t_game	*ft_init_game(char *map_file)
{
	t_game	*map;
	int		len;
	int		lines;

	ft_size_map(map_file, &len, &lines);
	map = malloc(sizeof(t_game));
	if (!map)
		return (NULL);
	ft_init_var(map, len, lines);
	map->map = ft_calloc(sizeof(char *), (lines + 1));
	if (!map->map)
		return (NULL);
	map->map = ft_fill_map(map_file, map);
	return (map);
}

char	**ft_fill_map(char *map_file, t_game *map)
{
	int	fd;
	int	i;

	fd = open(map_file, O_RDONLY);
	i = -1;
	while (++i < map->rows)
		map->map[i] = get_next_line(fd);
	close(fd);
	return (map->map);
}

void	ft_size_map(char *map_file, int *len, int *lines)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	lines[0] = 0;
	len[0] = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines[0]++;
		if (len[0] < (int)ft_strlen(line))
			len[0] = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_init_var(t_game *map, int len, int lines)
{
	map->rows = lines;
	map->cols = len;
	map->player_flag = 0;
	map->collect_flag = 0;
	map->exit_flag = 0;
	return ;
}
