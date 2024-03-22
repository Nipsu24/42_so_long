/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:30:57 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/22 14:59:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->textr = ft_calloc(1, sizeof(t_texture));
	game->textr->wall = mlx_load_png("./assets/png/Wall.png");
	game->textr->floor = mlx_load_png("./assets/png/Gras.png");
	game->textr->coll = mlx_load_png("./assets/png/collectible.png");
	game->textr->player = mlx_load_png("./assets/png/Lizard.png");
	game->textr->exit_s = mlx_load_png("./assets/png/Goal.png");
}

void	get_images(t_game *game, t_texture *textr)
{
	game->img = ft_calloc(1, sizeof(t_image));
	game->img->wall = mlx_texture_to_image(game->mlx, textr->wall);
	game->img->floor = mlx_texture_to_image(game->mlx, textr->floor);
	game->img->coll = mlx_texture_to_image(game->mlx, textr->coll);
	game->img->player = mlx_texture_to_image(game->mlx, textr->player);
	game->img->exit_s = mlx_texture_to_image(game->mlx, textr->exit_s);
	mlx_delete_texture(textr->wall);
	mlx_delete_texture(textr->floor);
	mlx_delete_texture(textr->coll);
	mlx_delete_texture(textr->player);
	mlx_delete_texture(textr->exit_s);
}

void	build_floor(t_game *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				mlx_image_to_window(game->mlx, img->floor, x * 32, y * 32);
				if (game->map[y][x] == '1')
					mlx_image_to_window(game->mlx, img->wall, x * 32, y * 32);
				if (game->map[y][x] == 'E')
					mlx_image_to_window(game->mlx, img->exit_s, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}
}

void	build_map(t_game *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		build_floor(game, img);
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] == 'P')
					mlx_image_to_window(game->mlx, img->player, x * 32, y * 32);
				if (game->map[y][x] == 'C')
					mlx_image_to_window(game->mlx, img->coll, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->wall);
	mlx_delete_image(game->mlx, game->img->floor);
	mlx_delete_image(game->mlx, game->img->coll);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_image(game->mlx, game->img->exit_s);
}
