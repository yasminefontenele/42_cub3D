/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliskam <eliskam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:24:10 by emencova          #+#    #+#             */
/*   Updated: 2024/11/04 13:01:33 by eliskam          ###   ########.fr       */
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

void	adjust_player_position(t_game *game, char direction)
{
	if (direction == 'E')
		game->player.pos_x -= COLLISION;
	else if (direction == 'W')
		game->player.pos_x += COLLISION;
	else if (direction == 'N')
		game->player.pos_y += COLLISION;
	else if (direction == 'S')
		game->player.pos_y -= COLLISION;
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
	while (game->map.layout[(int)(game->player.pos_x - COLLISION)]
		[(int)(game->player.pos_y)] == '1' ||
		game->map.layout[(int)(game->player.pos_x + COLLISION)]
		[(int)(game->player.pos_y)] == '1' ||
		game->map.layout[(int)(game->player.pos_x)]
		[(int)(game->player.pos_y - COLLISION)] == '1' ||
		game->map.layout[(int)(game->player.pos_x)]
		[(int)(game->player.pos_y + COLLISION)] == '1')
		adjust_player_position(game, direction);
	if (direction == 'N' || direction == 'S')
		player_ns_dir(game, direction);
	else if (direction == 'E' || direction == 'W')
		player_ew_dir(game, direction);
	game->player.mov_sp = MOVE_SPEED;
	game->player.rot_sp = ROTATE_SPEED;
}
