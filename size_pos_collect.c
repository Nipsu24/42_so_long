/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_pos_collect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:13:07 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/25 10:47:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Determines size of map*/
void	size_map(t_game *game, char **map)
{
	game->map_height = ft_array_height(map);
	game->map_width = ft_array_width(map);
}

/*Determines current position of player*/
void	cur_p_location(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->x_pos = 0;
	game->y_pos = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x_pos = j;
				game->y_pos = i;
			}
			j++;
		}
		i++;
	}
}

/*Compares P position with C position by looping through all C instances.
  If same location is detected, C images gets hidden. In case all Cs are found
  open exit gets enabled by disabling shut exit.*/
void	collect_all(t_game *game)
{
	int	i;

	i = 0;
	c_count(game);
	while (i < game->c_count)
	{
		if (game->y_pos == game->img->coll->instances[i].y / PX
			&& game->x_pos == game->img->coll->instances[i].x / PX)
		{
			if (game->img->coll->instances[i].enabled == true)
			{
				game->img->coll->instances[i].enabled = false;
				game->c_found++;
				break ;
			}
		}
		i++;
	}
	if (game->c_found == game->c_count)
		game->img->exit_s->enabled = false;
	if (game->map[game->img->player->instances->y / PX]
		[game->img->player->instances->x / PX] == 'E'
		&& game->img->exit_s->enabled == false)
		mlx_close_window(game->mlx);
}

/*Counts and returns all collectibles on map*/
int	c_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->c_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->c_count++;
			j++;
		}
		i++;
	}
	return (game->c_count);
}
void	delete_texture_success(t_game *game)
{
	mlx_delete_texture(game->textr->wall);
	mlx_delete_texture(game->textr->floor);
	mlx_delete_texture(game->textr->coll);
	mlx_delete_texture(game->textr->player);
	mlx_delete_texture(game->textr->exit_s);
	mlx_delete_texture(game->textr->exit_o);
	free(game->textr);
	game->textr = NULL;
}
