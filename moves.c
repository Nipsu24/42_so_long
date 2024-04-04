/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:29:48 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 12:33:08 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->img->player->instances->y / PX - 1]
		[game->img->player->instances->x / PX] != '1')
	{
		game->img->player->instances->y -= PX;
		game->count++;
		game->y_pos -= 1;
		ft_printf("moves: %d\n", game->count);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->img->player->instances->y / PX]
		[game->img->player->instances->x / PX - 1] != '1')
	{
		game->img->player->instances->x -= PX;
		game->count++;
		game->x_pos -= 1;
		ft_printf("moves: %d\n", game->count);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->img->player->instances->y / PX + 1]
		[game->img->player->instances->x / PX] != '1')
	{
		game->img->player->instances->y += PX;
		game->count++;
		game->y_pos += 1;
		ft_printf("moves: %d\n", game->count);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->img->player->instances->y / PX]
		[game->img->player->instances->x / PX + 1] != '1')
	{
		game->img->player->instances->x += PX;
		game->count++;
		game->x_pos += 1;
		ft_printf("moves: %d\n", game->count);
	}
}
