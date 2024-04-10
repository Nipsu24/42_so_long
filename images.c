/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:30:57 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/10 14:47:47 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_textures(t_game *game)
{
	game->textr = ft_calloc(1, sizeof(t_texture));
	if (!game->textr)
		return (0);
	game->textr->wall = mlx_load_png("./assets/png/Wall.png");
	if (!game->textr->wall)
		return (0);
	game->textr->floor = mlx_load_png("./assets/png/Gras.png");
	if (!game->textr->floor)
		return (0);
	game->textr->coll = mlx_load_png("./assets/png/collectible.png");
	if (!game->textr->coll)
		return (0);
	game->textr->player = mlx_load_png("./assets/png/Lizard.png");
	if (!game->textr->player)
		return (0);
	game->textr->exit_s = mlx_load_png("./assets/png/Goal_closed.png");
	if (!game->textr->exit_s)
		return (0);
	game->textr->exit_o = mlx_load_png("./assets/png/Goal.png");
	if (!game->textr->exit_o)
		return (0);
	return (1);
}

int	get_images(t_game *game, t_texture *textr)
{
	game->img = ft_calloc(1, sizeof(t_image));
	if (!game->img)
		return (0);
	game->img->wall = mlx_texture_to_image(game->mlx, textr->wall);
	game->img->floor = mlx_texture_to_image(game->mlx, textr->floor);
	game->img->coll = mlx_texture_to_image(game->mlx, textr->coll);
	game->img->player = mlx_texture_to_image(game->mlx, textr->player);
	game->img->exit_s = mlx_texture_to_image(game->mlx, textr->exit_s);
	game->img->exit_o = mlx_texture_to_image(game->mlx, textr->exit_o);
	mlx_delete_texture(textr->wall);
	mlx_delete_texture(textr->floor);
	mlx_delete_texture(textr->coll);
	mlx_delete_texture(textr->player);
	mlx_delete_texture(textr->exit_s);
	mlx_delete_texture(textr->exit_o);
	free(game->textr);
	if (!(resize_image(game)))
		return (0);
	return (1);
}

int	resize_image(t_game *game)
{
	if (!(mlx_resize_image(game->img->coll, 48, 48)))
		return (0);
	if (!(mlx_resize_image(game->img->wall, PX, PX)))
		return (0);
	if (!(mlx_resize_image(game->img->floor, PX, PX)))
		return (0);
	if (!(mlx_resize_image(game->img->player, PX, PX)))
		return (0);
	if (!(mlx_resize_image(game->img->exit_s, PX, PX)))
		return (0);
	if (!(mlx_resize_image(game->img->exit_o, PX, PX)))
		return (0);
	return (1);
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
				mlx_image_to_window(game->mlx, img->floor, x * PX, y * PX);
				if (game->map[y][x] == '1')
					mlx_image_to_window(game->mlx, img->wall, x * PX, y * PX);
				if (game->map[y][x] == 'E')
				{
					mlx_image_to_window(game->mlx, img->exit_o, x * PX, y * PX);
					mlx_image_to_window(game->mlx, img->exit_s, x * PX, y * PX);
				}
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
					mlx_image_to_window(game->mlx, img->player, x * PX, y * PX);
				if (game->map[y][x] == 'C')
					mlx_image_to_window(game->mlx, img->coll, x * PX, y * PX);
				x++;
			}
			y++;
		}
	}
}
