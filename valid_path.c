/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:23:30 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 16:19:33 by mmeier           ###   ########.fr       */
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
