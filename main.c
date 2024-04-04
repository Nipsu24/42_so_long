/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/04/04 14:31:57 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	size_map(game, game->map);
	game->mlx = mlx_init(game->map_width * PX,
			game->map_height * PX, "so_long", false);
	if (!(game->mlx))
		error_open_file();
	get_textures(game);
	get_images(game, game->textr);
	build_map(game, game->img);
	cur_p_location(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	delete_images(game);
	mlx_terminate(game->mlx);
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

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->wall);
	mlx_delete_image(game->mlx, game->img->floor);
	mlx_delete_image(game->mlx, game->img->coll);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_image(game->mlx, game->img->exit_s);
	mlx_delete_image(game->mlx, game->img->exit_o);
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
		return (ft_free_map(&map, &fd));
	game.map = ft_split(map, '\n');
	if (!game.map)
		return (ft_free_map(&map, &fd));
	free_and_close(&map, &fd);
	if (!init_game(&game))
		return (-1);
	return (0);
}
