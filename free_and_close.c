/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:33 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/10 14:10:05 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	ft_free_map(char **str, int *fd)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		close(*fd);
	}
	return (-1);
}

int	ft_free_empty(char **str, int *fd)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		close(*fd);
	}
	ft_printf("Error.\nMap is empty or a directory :(\n");
	return (-1);
}

void	free_and_close(char **str, int *fd)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		close(*fd);
	}
}

int	free_all(t_game *game, int n)
{
	if (n == 0)
	{
		delete_error_images(game);
		mlx_terminate(game->mlx);
		if (game->map)
			free_arr(game->map);
	}
	if (n == 1)
	{
		if (game->map)
			free_arr(game->map);
	}
	return (0);
}
