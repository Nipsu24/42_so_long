/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:29:48 by mmeier            #+#    #+#             */
/*   Updated: 2024/04/04 18:03:58 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Moving functions adjust location of player instance incase no "1" is present
  by using addition or substraction with pixel size (PX) (defined in header 
  file).y_pos & x_pos parallely tracked for easier reading purpose for later 
  use in function void collect_all (size_pos_collect.c)*/
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
