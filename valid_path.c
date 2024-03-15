/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:23:30 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/15 16:28:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char **map_2d)
{
	int	p_pos_x;
	int	p_pos_y;
	int	len_x;
	int	len_y;
	int	i;
	int j;

	p_pos_x = 0;
	p_pos_y = 0;
	len_x = ft_arr_strlen(map_2d);
	len_y = ft_array_size(map_2d);
	i = 0;
	player_pos(map_2d, &p_pos_x, &p_pos_y);
	map_2d = fill_map(map_2d, p_pos_x, p_pos_y, len_x, len_y);
	while (map_2d[i])
	{
		j = 0;
		while(map_2d[i][j])
		{
			if (map_2d[i][j] == 'E' || map_2d[i][j] == 'C')
				return (free_arr_valid_path(map_2d));
			j++;
		}
		i++;
	}
	return (1);
}

void	player_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
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

char	**fill_map(char **map, int x, int y, int len_x, int len_y)
{
	if (x < 0 || y < 0 || x >= len_x - 1 || y >= len_y - 1 
		|| map[x][y] == '1' || map[x][y] == 'X')
			return (0);
	if ((map[x + 1][y] == 'E' || map[x - 1][y] == 'E') 
		&& (map[x][y + 1] == '1' || map[x][y - 1] == '1'))
			return (0);
	if ((map[x + 1][y] == '1' || map[x - 1][y] == '1') 
		&& (map[x][y + 1] == 'E' || map[x][y - 1] == 'E'))
			return (0);
	if (map[x][y] == 'E' || map[x][y] == 'C')
		map[x][y] = '0';
	map[x][y] = 'X';
	fill_map(map, x + 1, y, len_x, len_y);
	fill_map(map, x - 1, y, len_x, len_y);
	fill_map(map, x, y + 1, len_x, len_y);
	fill_map(map, x, y - 1, len_x, len_y);
	return (map);
}
