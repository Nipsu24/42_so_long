/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_pos_collect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:13:07 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 12:33:11 by mmeier           ###   ########.fr       */
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
