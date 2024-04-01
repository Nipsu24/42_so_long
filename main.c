/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/03/25 16:56:25 by mmeier           ###   ########.fr       */
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

/*Determines size of map*/
void	size_map(t_game *game, char **map)
{
	game->map_height = ft_array_height(map);
	game->map_width = ft_array_width(map);
}

/*Determines current position of player*/
void	cur_p_location(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->player_pos->x = 0;
	game->player_pos->y = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos->x = j;
				game->player_pos->y = i;
			}
			j++;
		}
		i++;
	}
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 64, game->map_height * 64, "so_long", false);
	if (!(game->mlx))
		error_open_file();
	get_textures(game);
	get_images(game, game->textr);
	build_map(game, game->img);
	mlx_key_hook(game->mlx, my_key_hook, game);
	return (1);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	static t_game	*game;
	// int	i;

	// i = 0;
	game = param;
	// game->player_pos = malloc(sizeof(t_pos));
	// if (!game->player_pos)
	// 	return ;
	// while (game->map[i])
	// {
	// 	ft_printf("%s\n", game->map[i]);
	// 	i++;
	// }
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			// ft_printf("before y %d\n", game->player_pos->y);
			// ft_printf("before x %d\n", game->player_pos->x);
			//cur_p_location(game);
			// ft_printf("before y %d\n", game->img->player->instances->y);
			// ft_printf("before x %d\n", game->img->player->instances->x);
			if ((game->map[game->img->player->instances->y / 64 - 1]
				[game->img->player->instances->x / 64] != '1'))
			//if (game->map[game->player_pos->y - 1][game->player_pos->x] != '1')
			{
				game->img->player->instances->y -= 64;
				ft_printf("moves: %d\n", game->count);
				// ft_printf("after y %d\n", game->player_pos->y);
				// ft_printf("after x %d\n", game->player_pos->x);
				// ft_printf("after y %d\n", game->img->player->instances->y);
				// ft_printf("after x %d\n", game->img->player->instances->x);
			}
			// if (game->map[game->img->player->instances->y / 64][game->img->player->instances->x / 64] == 'C')
			// {
			// 	game->map[game->img->coll->instances->y][game->img->player->instances->enabled] = false;
			// 	//game->img->coll->instances->enabled = false;
			// 	game->c_count++;
			// }
		}
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			// cur_p_location(game);
			if ((game->map[game->img->player->instances->y / 64]
				[game->img->player->instances->x / 64 - 1] != '1'))
			// if (game->map[game->player_pos->y][game->player_pos->x - 1] != '1')
			{
				game->img->player->instances->x -= 64;
				ft_printf("moves: %d\n", game->count);
			}
		}
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			// cur_p_location(game);
			if ((game->map[game->img->player->instances->y / 64 + 1]
				[game->img->player->instances->x / 64] != '1'))
			// if (game->map[game->player_pos->y + 1][game->player_pos->x] != '1')
			{
				game->img->player->instances->y += 64;
				ft_printf("moves: %d\n", game->count);
			}
		}
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			// cur_p_location(game);
			if ((game->map[game->img->player->instances->y / 64]
				[game->img->player->instances->x / 64 + 1] != '1'))
			// if (game->map[game->player_pos->y][game->player_pos->x + 1] != '1')
			{
				game->img->player->instances->x += 64;
				ft_printf("moves: %d\n", game->count);
			}
		}
		collect_all(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	// free(game->player_pos);
	// game->player_pos = NULL;
}

void	collect_all(t_game *game)
{
	int	total_c;
	int	i;

	total_c = c_count(game);
	i = 0;
	//while (total_c > i)
	//{
		if (game->map[game->img->player->instances->y / 64][game->img->player->instances->x / 64] ==
			game->map[game->img->coll->instances[i].y / 64][game->img->coll->instances[i].x / 64] &&
			game->img->coll->instances[i].enabled == true) 
				{
					game->img->coll->instances[i].enabled = false;
					i++;
				}
		if (i == total_c)
			game->img->exit_s->enabled = false;
		if (game->map[game->img->player->instances->y / 64][game->img->player->instances->x / 64] ==
			game->map[game->img->exit_s->instances->y / 64][game->img->exit_s->instances->x / 64])
				mlx_close_window(game->mlx);
	//}
}


int	c_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->c_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->c_count++;
			j++;
		}
		i++;
	}
	return(game->c_count);
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
