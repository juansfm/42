/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:19:59 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/06/03 13:34:01 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../library/MLX42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 720
# define HEIGHT 480

typedef struct s_game
{
	int			rows;
	int			cols;
	char		**map;
	int			player_flag;
	int			exit_flag;
	int			collect_flag;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_game;

//SO_LONG
t_game	*ft_init_game(char *map_file);
char	**ft_fill_map(char *map_file, t_game *map);
void	ft_size_map(char *map_file, int *len, int *lines);
void	ft_init_var(t_game *map, int len, int lines);

//CHECKS
int		ft_check(t_game *map);
int		ft_check_map(t_game *map);
int		ft_check_args(int argc, char **argv);
int		ft_check_chars(t_game *map, int error);
int		ft_check_path(t_game *map);

//PATH
char	**ft_flood_fill(char **map, int x, int y);
char	**ft_copy(char **map);
int		ft_flood_check(char **map);

void	ft_init_window(t_game *map);
void	ft_keyhook(void *param);
#endif