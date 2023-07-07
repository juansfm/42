/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:14:47 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 11:32:36 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_textures(t_game *game)
{
	mlx_texture_t	*aux;

	aux = mlx_load_png("./textures/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/player.png");
	game->player = mlx_texture_to_image(game->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/collect.png");
	game->collect = mlx_texture_to_image(game->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, aux);
	mlx_delete_texture(aux);
}

void	ft_put_images(t_game *game)
{
	int	i;
	int	j;

	ft_put_first_depth(game);
	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->player, j * PIX, i * PIX);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * PIX, i * PIX);
		}
	}
}

void	ft_put_first_depth(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			mlx_image_to_window(game->mlx, game->floor, j * PIX, i * PIX);
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->collect, j * PIX, i * PIX);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit, j * PIX, i * PIX);
		}
	}
}
