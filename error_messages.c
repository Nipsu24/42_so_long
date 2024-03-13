/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:19 by mmeier            #+#    #+#             */
/*   Updated: 2024/03/13 16:57:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_arr_rectangle(char	**av)
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
	printf("Error. Map is not a rectangle :(\n");
	return (0);
}

int	free_arr_border(char **av)
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
	printf("Error. No valid borders :(\n");
	return (0);
}

int	free_arr_char(char **av)
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
	printf("Error. Map contains invalid characters :(\n");
	return (0);
}

int	free_arr_c_count(char **av)
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
	printf("Error. Map does not contain correct amount of characters:(\n");
	return (0);
}