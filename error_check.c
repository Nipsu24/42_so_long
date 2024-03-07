/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/07 16:54:02 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_ok(char *map)
{
	if (!map)
		return (0);
	if (!is_rectangle(map))
		return (0);
	// if (!valid_char(map))
	// 	return (0);
	// if (!p_e_c_count_ok(map))
	// 	return (0);
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

/*checks if all lines of the map have same amount of characters.
 empty spaces still to be handled*/
int	is_rectangle(char *map)
{
	int	i;
	int	j;
	int	c_count_rev;
	int	new_count;

	i = 0;
	j = 0;
	c_count_rev = 0;
	new_count = 0;
	while (map[c_count_rev] != '\n')
		c_count_rev++;
	i = c_count_rev + 1;
	while (map[i])
	{
		new_count = 0;
		while (map[i] && map[i] != '\n' && map[c_count_rev + 1] != ' ')
		{
			i++;
			new_count++;
		}
		if (c_count_rev != new_count)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char *map;

// 	map = "1234\n5678\n9101112";
// 	printf("nb of char in line:%d", is_rectangle(map));
// 	printf("nb of char in line:%d", is_rectangle_2(map));
// 	return (0);
// }