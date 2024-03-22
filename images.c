/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:30:57 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/22 14:32:02 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->texture->wall = mlx_load_png("./assets/png/Wall.png");
	game->texture->floor = mlx_load_png("./assets/png/Gras.png");
	game->texture->collectible = mlx_load_png("./assets/png/collectible.png");
	game->texture->player = mlx_load_png("./assets/png/Lizard.png");
	game->texture->exit_shut = mlx_load_png("./assets/png/Goal.png");
}

void	get_images(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->wall);
	game->image->floor = mlx_texture_to_image(game->mlx_ptr, game->texture->floor);
	game->image->collectible = mlx_texture_to_image(game->mlx_ptr, game->texture->collectible);
	game->image->player = mlx_texture_to_image(game->mlx_ptr, game->texture->player);
	game->image->exit_shut = mlx_texture_to_image(game->mlx_ptr, game->texture->exit_shut);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->collectible);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->exit_shut);
}

void	build_floor(t_game *game, t_image *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		while(game->map[y])
		{
			x = 0;
			while(game->map[y][x])
			{
				mlx_image_to_window(game->mlx_ptr, image->floor, x * 32, y * 32);
				if (game->map[y][x] == '1')
					mlx_image_to_window(game->mlx_ptr, image->wall, x * 32, y * 32);
				if (game->map[y][x] == 'E')
					mlx_image_to_window(game->mlx_ptr, image->exit_shut, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}
	
}

void	build_map(t_game *game, t_image *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		build_floor(game, image);
		while(game->map[y])
		{
			x = 0;
			while(game->map[y][x])
			{
				if (game->map[y][x] == 'P')
					mlx_image_to_window(game->mlx_ptr, image->player, x * 32, y * 32);
				if (game->map[y][x] == 'C')
					mlx_image_to_window(game->mlx_ptr, image->collectible, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}

}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx_ptr, game->image->wall);
	mlx_delete_image(game->mlx_ptr, game->image->floor);
	mlx_delete_image(game->mlx_ptr, game->image->collectible);
	mlx_delete_image(game->mlx_ptr, game->image->player);
	mlx_delete_image(game->mlx_ptr, game->image->exit_shut);
}
