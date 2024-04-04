/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 17:18:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_ok(char *map)
{
	char	**map_2d;

	map_2d = ft_split(map, '\n');
	if (!map_2d)
		return (-1);
	if (!is_rectangle(map_2d))
		return (free_arr_rectangle(map_2d));
	if (!correct_size(map_2d))
		return (free_arr_size(map_2d));
	if (!borders_top_down(map_2d))
		return (free_arr_border(map_2d));
	if (!borders_left_right(map_2d))
		return (free_arr_border(map_2d));
	if (!valid_char(map))
		return (free_arr_char(map_2d));
	if (!p_e_c_count_ok(map))
		return (free_arr_c_count(map_2d));
	if (!valid_path(map_2d))
		return (free_arr_valid_path(map_2d));
	return (free_arr(map_2d));
}

/*Checks if all lines of the map have same amount of characters.*/
int	is_rectangle(char *map_2d[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map_2d[j])
	{
		if (ft_strlen(map_2d[i]) != ft_strlen(map_2d[j]))
			return (0);
		j++;
	}
	return (1);
}

/*Checks if map is not exceeding set limit of 40 (x) x 20 (y) characters.*/
int	correct_size(char **map)
{
	if (ft_array_height(map) > 20)
		return (0);
	if (ft_array_width(map) > 40)
		return (0);
	return (1);
}
/*Checks if there are any other chars from '1s' in 1st & last row.
  'Last - 1', in order to not include array with 'NULL-terminator'*/
int	borders_top_down(char *map_2d[])
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = ft_array_height(map_2d);
	while (map_2d[0][i])
	{
		if (map_2d[0][i] != '1')
			return (0);
		i++;
	}
	while (map_2d[last - 1][j])
	{
		if (map_2d[last - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

/*Checks if there are any other chars from '1s' in 1st & last 
  index of given string (i = left border, j = right border). 
  "right border -1" (2nd while loop) due to array indexing*/
int	borders_left_right(char *map_2d[])
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = ft_array_height(map_2d);
	while (last != i)
	{
		if (map_2d[i][0] != '1')
			return (0);
		i++;
	}
	while (last != j)
	{
		if (map_2d[j][ft_strlen(map_2d[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}
