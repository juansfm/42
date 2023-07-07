/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:03:56 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/05 18:17:46 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_window(t_game *game)
{
	game->moves = 0;
	game->collect_count = game->collect_flag;
	game->mlx = mlx_init(game->cols * PIX, game->rows * PIX, "So_long", true);
	if (!game->mlx)
		return ;
	ft_put_textures(game);
	ft_put_images(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && ft_valid_move(game,
			(game->player->instances[0].y / PIX) - 1,
			game->player->instances[0].x / PIX))
		game->player->instances[0].y -= 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && ft_valid_move(game,
			(game->player->instances[0].y / PIX) + 1,
			game->player->instances[0].x / PIX))
		game->player->instances[0].y += 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && ft_valid_move(game,
			game->player->instances[0].y / PIX, (game->player->instances[0].x
				/ PIX - 1)))
		game->player->instances[0].x -= 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && ft_valid_move(game,
			game->player->instances[0].y / PIX, (game->player->instances[0].x
				/ PIX + 1)))
		game->player->instances[0].x += 64;
}

int	ft_valid_move(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		return (0);
	game->moves++;
	ft_putstr_fd("MOVES:", 1);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	if (game->map[x][y] == 'C')
		ft_collectibles(game, x, y);
	if (game->map[x][y] == 'E' && game->collect_count == 0)
	{
		ft_putstr_fd("YOU WON!\n", 1);
		mlx_close_window(game->mlx);
	}
	return (1);
}

void	ft_free(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i] != NULL)
		free(matrix[i]);
	free(matrix);
}

void	ft_collectibles(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < game->collect_flag)
	{
		if (game->collect->instances[i].x == y * PIX
			&& game->collect->instances[i].y == x * PIX)
		{
			game->collect->instances[i].enabled = false;
			game->collect_count--;
			game->map[x][y] = '0';
		}
	}
}
