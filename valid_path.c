/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:23:30 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/10 15:07:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Shows invalid path in case any 'E' or 'C' are detected after
  flood filling map via 'fill_map-function'*/
int	valid_path(char **map_2d)
{
	int	p_pos_x;
	int	p_pos_y;
	int	i;
	int	j;

	p_pos_x = 0;
	p_pos_y = 0;
	i = 0;
	j = 0;
	player_pos(map_2d, &p_pos_x, &p_pos_y);
	fill_map(&map_2d, p_pos_x, p_pos_y);
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == 'E' || map_2d[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*Determines player position and by dereferencing updates the
  values in the valid_path function*/
void	player_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

/*Uses recursion in order to fill the map with 'Xs'. 
  In case '1' or 'X' are detected, function quits.*/
void	fill_map(char ***map, int x, int y)
{
	if ((*map)[y][x] == '1' || (*map)[y][x] == 'X')
		return ;
	(*map)[y][x] = 'X';
	fill_map(map, x + 1, y);
	fill_map(map, x - 1, y);
	fill_map(map, x, y + 1);
	fill_map(map, x, y - 1);
	return ;
}

/*Deletes texture in case texture creation fails. 
  Otherwise texture deletion handled in get_images*/
int	delete_textures(t_game *game)
{
	if (game->textr)
	{
		if (game->textr->wall)
			mlx_delete_texture(game->textr->wall);
		if (game->textr->floor)
			mlx_delete_texture(game->textr->floor);
		if (game->textr->coll)
			mlx_delete_texture(game->textr->coll);
		if (game->textr->player)
			mlx_delete_texture(game->textr->player);
		if (game->textr->exit_s)
			mlx_delete_texture(game->textr->exit_s);
		if (game->textr->exit_o)
			mlx_delete_texture(game->textr->exit_o);
		free(game->textr);
		game->textr = NULL;
	}
	return (0);
}

/*Deletes images in case image creation fails (incl. texture deletion)*/
int	delete_error_images(t_game *game)
{
	delete_textures(game);
	if (game->img)
	{
		if (game->img->wall)
			mlx_delete_image(game->mlx, game->img->wall);
		if (game->img->floor)
			mlx_delete_image(game->mlx, game->img->floor);
		if (game->img->coll)
			mlx_delete_image(game->mlx, game->img->coll);
		if (game->img->player)
			mlx_delete_image(game->mlx, game->img->player);
		if (game->img->exit_s)
			mlx_delete_image(game->mlx, game->img->exit_s);
		if (game->img->exit_o)
			mlx_delete_image(game->mlx, game->img->exit_o);
		free(game->img);
		game->img = NULL;
	}
	return (0);
}
