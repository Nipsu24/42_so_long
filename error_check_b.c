/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 17:08:25 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
