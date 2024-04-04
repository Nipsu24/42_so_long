/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:33 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 14:34:01 by mmeier           ###   ########.fr       */
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
	return (0);
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
