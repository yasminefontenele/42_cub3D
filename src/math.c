/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliskam <eliskam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:17:50 by emencova          #+#    #+#             */
/*   Updated: 2024/11/02 20:44:43 by eliskam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	calculate_perpendicular_distance(t_game *game, t_ray *ray)
{
	double	wall_dist;

	if (ray->wall_side == 1 || ray->wall_side == 2)
		wall_dist = (ray->grid_x - game->player.pos_x
				+ (1 - ray->step_directx) / 2) / ray->direc_x;
	else
		wall_dist = (ray->grid_y - game->player.pos_y
				+ (1 - ray->step_directy) / 2) / ray->direc_y;
	return (wall_dist);
}

void	calculate_draw_positions(t_ray *ray)
{
	int	line_height;

	line_height = (int)(HEIGHT / ray->wall_dist);
	ray->start_draw = (-line_height / 2 + HEIGHT / 2);
	ray->end_draw = (line_height / 2 + HEIGHT / 2);
	if (ray->start_draw < 0)
		ray->start_draw = 0;
	if (ray->end_draw >= HEIGHT)
		ray->end_draw = HEIGHT - 1;
}

void	calculate_ray_direction(t_game *game, int x, t_ray *ray)
{
	double	camerax;

	camerax = 2 * x / (double)WIDTH - 1;
	ray->direc_x = game->player.dir_x + game->player.plane_x * camerax;
	ray->direc_y = game->player.dir_y + game->player.plane_y * camerax;
}

void	calculate_delta_distance(t_ray *ray)
{
	if (ray->direc_x == 0)
		ray->dist_deltax = 1e30;
	else
		ray->dist_deltax = fabs(1 / ray->direc_x);
	if (ray->direc_y == 0)
		ray->dist_deltay = 1e30;
	else
		ray->dist_deltay = fabs(1 / ray->direc_y);
}

void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->direc_x < 0)
	{
		ray->step_directx = -1;
		ray->dist_to_sidex = (game->player.pos_x - ray->grid_x)
			* ray->dist_deltax;
	}
	else
	{
		ray->step_directx = 1;
		ray->dist_to_sidex = (ray->grid_x + 1.0 - game->player.pos_x)
			* ray->dist_deltax;
	}
	if (ray->direc_y < 0)
	{
		ray->step_directy = -1;
		ray->dist_to_sidey = (game->player.pos_y - ray->grid_y)
			* ray->dist_deltay;
	}
	else
	{
		ray->step_directy = 1;
		ray->dist_to_sidey = (ray->grid_y + 1.0 - game->player.pos_y)
			* ray->dist_deltay;
	}
}
