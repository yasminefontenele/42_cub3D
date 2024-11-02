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
		wall_dist = (ray->grid_x - game->player.pos_x + (1 - ray->step_directx) / 2) / ray->direc_x;
	else
		wall_dist = (ray->grid_y - game->player.pos_y + (1 - ray->step_directy) / 2) / ray->direc_y;
	return (wall_dist);
}


void	calculate_ray_direction(t_game *game, int x, t_ray *ray)
{
	double	camerax;

	camerax = 2 * x / (double)WIDTH - 1;
	ray->direc_x = game->player.dir_x + game->player.plane_x * camerax;
	ray->direc_y = game->player.dir_y + game->player.plane_y * camerax;
}

