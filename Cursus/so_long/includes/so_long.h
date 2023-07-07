/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:19:59 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 16:51:55 by jsaavedr         ###   ########.fr       */
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
# define PIX 64

typedef struct s_game
{
	int			rows;
	int			cols;
	char		**map;
	int			player_flag;
	int			exit_flag;
	int			collect_flag;
	int			collect_count;
	int			moves;
	mlx_t		*mlx;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
}				t_game;

//SO_LONG
t_game			*ft_init_game(char *map_file);
char			**ft_fill_map(char *map_file, t_game *map);
void			ft_size_map(char *map_file, int *len, int *lines);
void			ft_init_var(t_game *map, int len, int lines);

//CHECKS
void			ft_check_args(int argc, char **argv);
void			ft_check_map(t_game *map);
void			ft_check_chars(t_game *map);
void			ft_error(char error, t_game *map);

//PATH
void			ft_check_path(t_game *map);
char			**ft_copy(char **map);
char			**ft_flood_fill(char **map, int x, int y);
int				ft_flood_check(char **map);

//IMAGES
void			ft_put_textures(t_game *game);
void			ft_put_images(t_game *game);
void			ft_put_first_depth(t_game *game);

void			ft_init_window(t_game *game);
void			ft_keyhook(mlx_key_data_t keydata, void *param);
int				ft_valid_move(t_game *game, int x, int y);
void			ft_free(char **matrix);
void			ft_collectibles(t_game *game, int x, int y);

#endif