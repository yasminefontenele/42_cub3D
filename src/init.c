/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:24:10 by emencova          #+#    #+#             */
/*   Updated: 2024/11/04 15:12:09 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	player_ns_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

void	player_ew_dir(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

int	initialize_game_data(t_game *game)
{
	game->data.mlx = mlx_init();
	if (!game->data.mlx)
		return (0);
	return (1);
}

void	init_player(t_game *game, int x, int y, char direction)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	if (direction == 'N' || direction == 'S')
		player_ns_dir(game, direction);
	else if (direction == 'E' || direction == 'W')
		player_ew_dir(game, direction);
	game->player.mov_sp = MOVE_SPEED;
	game->player.rot_sp = ROTATE_SPEED;
}
