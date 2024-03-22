/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:19 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/22 12:04:39 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrong_format_error(void)
{
	ft_printf("Error.\nMap is in wrong format :(\n");
	return (0);
}

int	error_open_file(void)
{
	ft_printf("Error.\nFile could not be opened :(\n");
	return (1);
}

int	free_arr(char **av)
{
	int	j;

	j = 0;
	if (av[j] == NULL || av == NULL)
		return (-1);
	while (av[j])
	{
		free(av[j]);
		av[j] = NULL;
		j++;
	}
	free(av);
	av = NULL;
	return (1);
}

int	error_empty_map(void)
{
	ft_printf("Error.\nMap is empty :(\n");
	return (0);
}
