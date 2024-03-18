/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/18 12:07:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/*Checks if there are any other chars from '1s' in 1st & last row.
  'Last - 1', in order to not include array with '/NULL-terminator'*/
int	borders_top_down(char *map_2d[])
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = ft_array_size(map_2d);
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
  index of string. "Last -1" due to array indexing*/
int	borders_left_right(char *map_2d[])
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = ft_array_size(map_2d);
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

/*Checks whether map consists only of valid characters. Takes also care
  of empty lines with j-while-loop*/

int	valid_char(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (0);
		i++;
	}
	while (map[j])
	{
		if (map[0] == '\n' || (map[j] == '\n' && map[j + 1] == '\n')
			|| map[ft_strlen(map) - 1] == '\n')
			return (0);
		j++;
	}
	return (1);
}

/*Counts occurence of players, exits and collectibles on the map*/
int	p_e_c_count_ok(char *map)
{
	int	i;
	int	p_count;
	int	e_count;
	int	c_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p_count++;
		if (map[i] == 'E')
			e_count++;
		if (map[i] == 'C')
			c_count++;
		i++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (0);
	else
		return (1);
}
