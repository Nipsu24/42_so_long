/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/13 15:52:06 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_map
{
    int x;
    int y;
}   t_map;

typedef struct s_data
{
	void    *mlx_ptr; // MLX pointer
	void    *win_ptr; // MLX window pointer
	void    *textures[5]; // MLX image pointers (on the stack)
	t_map   *map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

char	*ft_read_map(int fd);
char	*ft_free(char **str);
int		map_is_ok(char *map);
int	    p_e_c_count_ok(char *map);
int	    valid_char(char *map);
int		is_rectangle(char *map_2d[]);
int		ft_free_map(void **str);
int		borders_top_down(char *map_2d[]);
int		borders_left_right(char *map_2d[]);
int		ft_array_size(char **array);
int		free_arr_border(char **av);
int		free_arr_rectangle(char	**av);
int		free_arr_char(char **av);
int		free_arr_c_count(char **av);

#endif
