/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/22 10:54:35 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;


typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
	mlx_texture_t	*exit_shut;
	mlx_texture_t	*exit_open;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
	mlx_image_t	*exit_shut;
	mlx_image_t	*exit_open;
}	t_image;

typedef struct s_game
{
	struct s_texture	*texture;
	struct s_image		*image;
	mlx_t				*mlx_ptr;
	char				**map;
	int					map_width;
	int					map_height;
}	t_game;

char	*ft_read_map(int fd);
char	*ft_free(char **str);
int		map_is_ok(char *map);
int		p_e_c_count_ok(char *map);
int		valid_char(char *map);
int		is_rectangle(char *map_2d[]);
int		ft_free_map(void **str);
int		borders_top_down(char *map_2d[]);
int		borders_left_right(char *map_2d[]);
int		ft_array_height(char **array);
int		free_arr_border(char **av);
int		free_arr_rectangle(char	**av);
int		free_arr_char(char **av);
int		free_arr_c_count(char **av);
int		valid_path(char **map_2d);
int		file_format(char *str);
int		wrong_format_error(void);
int		error_open_file(void);
int		free_arr(char **av);
void	player_pos(char **map, int *x, int *y);
void	fill_map(char ***map, int x, int y);
int		free_arr_valid_path(char **av);
int		error_empty_map(void);
int		ft_array_width(char **array);
void	size_map(t_game *game, char **map);
int		init_game(t_game *game);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	build_floor(t_game *game, t_image *image);
void	build_map(t_game *game, t_image *image);
void	delete_images(t_game *game);

#endif