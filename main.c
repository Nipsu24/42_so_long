/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/03/21 17:14:27 by mmeier           ###   ########.fr       */
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
	game->mlx_ptr = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx_ptr))
		error_open_file();
	get_textures(game);
	get_images(game);
	draw_map(game, game->image);	
}

void	get_textures(t_game *game)
{
	game->texture->wall = mlx_load_png("./assets/Wall.png");
	game->texture->floor = mlx_load_png("./assets/Gras.png");
	game->texture->collectible = mlx_load_png("./assets/collectible.png");
	game->texture->player = mlx_load_png("./assets/Lizard.png");
	game->texture->exit_shut = mlx_load_png("./assets/Goal.png");
}

void	get_images(t_game *game)
{
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->wall);
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->collectible);
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->player);
	game->image->wall = mlx_texture_to_image(game->mlx_ptr, game->texture->exit_shut);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->collectible);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->exit_shut);
}

void	draw_floor(t_game *game, t_image *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		while(game->map[y])
		{
			x = 0;
			while(game->map[y][x])
			{
				game->map[y][x] == mlx_image_to_window(game->mlx_ptr, image->floor, x * 32, y * 32);
				if (game->map[y][x] == '1')
					game->map[y][x] == mlx_image_to_window(game->mlx_ptr, image->wall, x * 32, y * 32);
				if (game->map[y][x] == 'E')
					game->map[y][x] == mlx_image_to_window(game->mlx_ptr, image->exit_shut, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}
	
}

void	draw_map(t_game *game, t_image *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	{
		draw_floor(game, image);
		while(game->map[y])
		{
			x = 0;
			while(game->map[y][x])
			{
				if (game->map[y][x] == 'P')
					game->map[y][x] == mlx_image_to_window(game->mlx_ptr, image->player, x * 32, y * 32);
				if (game->map[y][x] == 'C')
					game->map[y][x] == mlx_image_to_window(game->mlx_ptr, image->collectible, x * 32, y * 32);
				x++;
			}
			y++;
		}
	}

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
	//ft_printf("%s\n", map);
	if (!map_is_ok(map))
	{
		free(map);
		close(fd);
		return (0);
	}
	free(map);
	close(fd);
	game.map = ft_read_map(fd);
	size_map(&game, game.map);
	init_game(&game);
	if (mlx_image_to_window(mlx_ptr, img, 0, 0) < 0)
		error();
	mlx_loop(game.mlx_ptr);
	mlx_delete_image(mlx_ptr, img);
	mlx_terminate(mlx_ptr);
	return (0);
}
