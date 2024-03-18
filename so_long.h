/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/18 13:50:25 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
//# include "mlx/mlx.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		player;
	int		exit;
	int		collectibles;
}	t_map;

char	*ft_read_map(int fd);
char	*ft_free(char **str);
int		map_is_ok(char *map);
int		p_e_c_count_ok(char *map);
int		valid_char(char *map);
int		is_rectangle(char *map_2d[]);
int		ft_free_map(void **str);
int		borders_top_down(char *map_2d[]);
int		borders_left_right(char *map_2d[]);
int		ft_array_size(char **array);
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

#endif
