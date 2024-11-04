/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:39 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/04 14:29:44 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	can_move_to(t_game *game, double newx, double newy)
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;

	xmin = (int)(newx);
	xmax = (int)(newx);
	ymin = (int)(newy);
	ymax = (int)(newy);
	return (game->map.layout[ymin][xmin] != '1' &&
			game->map.layout[ymax][xmin] != '1' &&
			game->map.layout[ymin][xmax] != '1' &&
			game->map.layout[ymax][xmax] != '1');
}
/*
int	can_move_to(t_game *game, double newx, double newy)
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;

	xmin = (int)(newx - COLLISION);
	xmax = (int)(newx + COLLISION);
	ymin = (int)(newy - COLLISION);
	ymax = (int)(newy + COLLISION);
	return (game->map.layout[ymin][xmin] != '1' &&
			game->map.layout[ymax][xmin] != '1' &&
			game->map.layout[ymin][xmax] != '1' &&
			game->map.layout[ymax][xmax] != '1');
}
*/

void	move_y(t_game *game, char direction)
{
	double	movespeed;
	double	newx;
	double	newy;

	newx = 0;
	newy = 0;
	movespeed = game->player.mov_sp;
	if (direction == 'N')
	{
		newx = game->player.pos_x - game->player.dir_x * movespeed;
		newy = game->player.pos_y - game->player.dir_y * movespeed;
	}
	else if (direction == 'S')
	{
		newx = game->player.pos_x + game->player.dir_x * movespeed;
		newy = game->player.pos_y + game->player.dir_y * movespeed;
	}
	if (can_move_to(game, newx, game->player.pos_y))
		game->player.pos_x = newx;
	if (can_move_to(game, game->player.pos_x, newy))
		game->player.pos_y = newy;
}

void	move_x(t_game *game, char direction)
{
	double	movespeed;
	double	newx;
	double	newy;

	newx = 0;
	newy = 0;
	movespeed = game->player.mov_sp;
	if (direction == 'E')
	{
		newx = game->player.pos_x - game->player.dir_y * movespeed;
		newy = game->player.pos_y + game->player.dir_x * movespeed;
	}
	else if (direction == 'W')
	{
		newx = game->player.pos_x + game->player.dir_y * movespeed;
		newy = game->player.pos_y - game->player.dir_x * movespeed;
	}
	if (can_move_to(game, newx, game->player.pos_y))
		game->player.pos_x = newx;
	if (can_move_to(game, game->player.pos_x, newy))
		game->player.pos_y = newy;
}

void	move_player(t_game *game, char direction)
{
	if (direction == 'N')
		move_y(game, direction);
	else if (direction == 'S')
		move_y(game, direction);
	else if (direction == 'W')
		move_x(game, direction);
	else if (direction == 'E')
		move_x(game, direction);
}

void	rotate_player(t_game *game, float angle)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) \
		+ game->player.dir_y * sin(angle);
	game->player.dir_y = -olddirx * sin(angle) \
		+ game->player.dir_y * cos(angle);
	oldplanex = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle) \
		+ game->player.plane_y * sin(angle);
	game->player.plane_y = -oldplanex * sin(angle) \
		+ game->player.plane_y * cos(angle);
	raycasting(game);
}
