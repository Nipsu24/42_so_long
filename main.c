/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/03/22 15:01:18 by mmeier           ###   ########.fr       */
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

void	size_map(t_game *game, char **map)
{
	game->map_height = ft_array_height(map);
	game->map_width = ft_array_width(map);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx))
		error_open_file();
	get_textures(game);
	get_images(game, game->textr);
	build_map(game, game->img);
	return (1);
}

int	main(int ac, char *av[])
{
	int				fd;
	char			*map;
	static t_game	game;

	if (ac != 2)
		return (0);
	if (!file_format(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_open_file());
	map = ft_read_map(fd);
	if (!map_is_ok(map))
	{
		free(map);
		close(fd);
		return (0);
	}
	game.map = ft_split(map, '\n');
	if (!game.map)
		return (-1);
	free(map);
	map = NULL;
	close(fd);
	size_map(&game, game.map);
	init_game(&game);
	mlx_loop(game.mlx);
	delete_images(&game);
	mlx_terminate(game.mlx);
	return (0);
}
