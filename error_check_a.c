/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:10:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/03 17:12:01 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks if file is in correct .ber format. "str + len_str - len_ext" moves 
  str until file extension and compares following characters with chars of 
  string "extension". If file is only named ".ber", error is returned, too.*/
int	file_format(char *str)
{
	char	*extension;
	int		len_str;
	int		len_ext;

	extension = ".ber";
	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	if (len_str <= len_ext
		|| (ft_strncmp(str + len_str - len_ext, extension, len_str) != 0))
		return (wrong_format_error());
	else
		return (1);
}

int	map_is_ok(char *map)
{
	char	**map_2d;

	if (!map)
		error_empty_map();
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
		return (free_arr_c_count(map_2d));
	return (free_arr(map_2d));
}

int	correct_size(char **map)
{
	if (ft_array_height(map) > 20)
		return (0);
	if (ft_array_width(map) > 40)
		return (0);
	return (1);
}
