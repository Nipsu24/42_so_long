/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/03/18 13:52:19 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
// {
//     void    *mlx_ptr;
//     void    *win_ptr;

//     mlx_ptr = mlx_init();
//     if (!mlx_ptr)
//         return(ft_free_map(&mlx_ptr));
//     win_ptr = mlx_new_window(mlx_ptr, 600, 400, "test!");
//     if (!win_ptr)
//         return(ft_free_map(&mlx_ptr));
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     mlx_destroy_display(mlx_ptr);
//     return (ft_free_map(&mlx_ptr));
// }

/*Checks if file is in correct .ber format. "str + len_str - len_ext" moves 
  str until file extension and compares following characters with chars of 
  string "extension"*/
int	file_format(char *str)
{
	char	*extension = ".ber";
	int		len_str;
	int		len_ext;

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

int	main(int ac, char *av[])
{
	int		fd;
	char	*map;

	if (ac != 2)
		return (0);
	if (!file_format(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_open_file());
	map = ft_read_map(fd);
	ft_printf("%s\n", map);
	if (!map_is_ok(map))
	{
		free(map);
		close(fd);
		return (0);
	}
	return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*map;

// 	fd = open("./maps/rectangular.ber", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	map = ft_read_map(fd);
// 	if (!map_is_ok(map))
// 		ft_putstr_fd("Error\n", 1);//return ()
// 	printf("%s", map);
// 	free(map);
// 	close(fd);
// 	return (0);
// }