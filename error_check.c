/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/13 16:53:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_ok(char *map)
{
	char	**map_2d;

	if (!map)
		return (0);
	map_2d = ft_split(map, '\n');
	if (map_2d == NULL)
		return (-1);
	if (!is_rectangle(map_2d))
		return (free_arr_rectangle(map_2d));
	if (!borders_top_down(map_2d))
		return (free_arr_border(map_2d));
	if (!borders_left_right(map_2d))
		return (free_arr_border(map_2d));
	if (!valid_char(map))
		return (free_arr_char(map_2d));
	if (!p_e_c_count_ok(map))
		return (free_arr_c_count(map_2d));
	return (1);
}

/*checks whether map consists only of valid characters*/
int	valid_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*counts occurence of players, exits and collectibles on the map*/
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

/*checks if all lines of the map have same amount of characters.*/
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

/*checks if there are any other chars from '1s' in 1st & last row.
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

/*checks if there are any other chars from '1s' in 1st & last 
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

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	if(!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	main(void)
{
	int		fd;
	char	*map;

	fd = open("./maps/rectangular.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	map = ft_read_map(fd);
	printf("%s", map);
	if (!map_is_ok(map))
		return (0);
	free(map);
	close(fd);
	return (0);
}