/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/06 16:18:11 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_read_map(int fd);
char	*ft_free(char **str);
int 	map_is_ok(char *map);


#endif
