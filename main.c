/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/04/17 15:30:31 by mmeier           ###   ########.fr       */
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
		|| (ft_strncmp(str + len_str - len_ext, extension, len_ext) != 0))
		return (0);
	else
		return (1);
}

/*Initialises MLX42 instance (window), textures/images and key hook*/
int	init_game(t_game *game)
{
	game->count = 0;
	size_map(game, game->map);
	game->mlx = mlx_init(game->map_width * PX,
			game->map_height * PX, "so_long", false);
	if (PX > 100)
		return (0);
	if (!(game->mlx))
		return (0);
	if (!get_textures(game))
		return (delete_textures(game));
	if (!get_images(game, game->textr))
		return (delete_error_images(game));
	build_map(game, game->img);
	cur_p_location(game);
	mlx_key_hook(game->mlx, my_key_hook, game);
	mlx_loop(game->mlx);
	delete_images(game);
	mlx_terminate(game->mlx);
	return (1);
}

/*Detects key press and passes information to respective move functions
  where it is checked whether moves can be conducted. Afterwards check
  if player is on collectible is conducted.*/
void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

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

/*Deletes images for successful path, otherwise
  see function: delete_error_images*/
void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->wall);
	mlx_delete_image(game->mlx, game->img->floor);
	mlx_delete_image(game->mlx, game->img->coll);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_image(game->mlx, game->img->exit_s);
	mlx_delete_image(game->mlx, game->img->exit_o);
	free(game->img);
}

int	main(int ac, char *av[])
{
	int		fd;
	char	*map;
	t_game	game;

	if (ac != 2)
		return (wrong_ac_count());
	if (!file_format(av[1]))
		return (wrong_format_error());
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_open_file());
	map = ft_read_map(fd);
	if (!map || !map[0])
		return (ft_free_empty(&map, &fd));
	if (!map_is_ok(map))
		return (ft_free_map(&map, &fd));
	game.map = ft_split(map, '\n');
	if (!game.map)
		return (ft_free_map(&map, &fd));
	free_and_close(&map, &fd);
	if (!init_game(&game))
		return (free_all(&game, 0));
	return (free_all(&game, 1));
}
