/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:03:56 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/06/03 19:31:33 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_window(t_game *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	if (!map->mlx)
		return ;
	map->img = mlx_new_image(map->mlx, 256, 256);
	if (!map->img)
		return ;
	ft_memset(map->img->pixels, 255, map->img->width * map->img->height * sizeof(int32_t));
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) > 0)
		return ;
	printf("Hola\n");
	mlx_loop_hook(map->mlx, ft_keyhook, map->mlx);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
}

void	ft_keyhook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		printf("ESC\n");
		mlx_close_window(param);
	}
	if (mlx_is_key_down(param, MLX_KEY_UP))
	{
		printf("UP\n");
	}
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
	{
		printf("DOWN\n");
	}
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
	{
		printf("LEFT\n");
	}
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	{
		printf("RIGHT\n");
	}
}
