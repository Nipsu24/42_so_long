/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/04/03 17:21:19 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 64, game->map_height * 64, "so_long", false);
	if (!(game->mlx))
		error_open_file();
	get_textures(game);
	get_images(game, game->textr);
	build_map(game, game->img);
	cur_p_location(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	return (1);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	static t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_up(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_left(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_down(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_right(game);
		collect_all(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
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
