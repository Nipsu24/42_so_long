/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/25 10:14:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/include/MLX42/MLX42.h"

# define BUFFER_SIZE 1
# define PX 64

typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*coll;
	mlx_texture_t	*player;
	mlx_texture_t	*exit_s;
	mlx_texture_t	*exit_o;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*coll;
	mlx_image_t	*player;
	mlx_image_t	*exit_s;
	mlx_image_t	*exit_o;
}	t_image;

typedef struct s_game
{
	struct s_texture	*textr;
	struct s_image		*img;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					count;
	int					c_count;
	int					c_found;
	int					x_pos;
	int					y_pos;
}	t_game;

/*main*/
int		file_format(char *str);
int		init_game(t_game *game);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	delete_images(t_game *game);

/*free_and_close*/
char	*ft_free(char **str);
int		ft_free_map(char **str, int *fd);
int		ft_free_empty(char **str, int *fd);
void	free_and_close(char **str, int *fd);
int		free_all(t_game *game, int n);

/*error_check*/
int		map_is_ok(char *map);
int		is_rectangle(char *map_2d[]);
int		correct_size(char **map);
int		borders_top_down(char *map_2d[]);
int		borders_left_right(char *map_2d[]);
int		p_e_c_count_ok(char *map);
int		valid_char(char *map);

/*valid_path / delete images & textures*/
int		valid_path(char **map_2d);
void	player_pos(char **map, int *x, int *y);
void	fill_map(char ***map, int x, int y);
int		delete_textures(t_game *game);
int		delete_error_images(t_game *game);

/*error_messages*/
int		free_arr_rectangle(char	**av);
int		free_arr_border(char **av);
int		free_arr_char(char **av);
int		free_arr_c_count(char **av);
int		free_arr_valid_path(char **av);
int		wrong_format_error(void);
int		error_open_file(void);
int		free_arr(char **av);
int		free_arr_size(char **av);
int		wrong_ac_count(void);

/*images*/
int		get_textures(t_game *game);
int		get_images(t_game *game, t_texture *texture);
int		resize_image(t_game *game);
void	build_floor(t_game *game, t_image *image);
void	build_map(t_game *game, t_image *image);

/*size_pos_collect*/
void	size_map(t_game *game, char **map);
void	cur_p_location(t_game *game);
void	collect_all(t_game *game);
int		c_count(t_game *game);
void	delete_texture_success(t_game *game);

/*moves*/
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

/*utils*/
char	*ft_read_map(int fd);
int		ft_array_height(char **array);
int		ft_array_width(char **array);

#endif