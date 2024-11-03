/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliskam <eliskam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:14:46 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/02 21:18:19 by eliskam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_dda(t_game *game, t_ray *ray)
{
	calculate_delta_distance(ray);
	calculate_step_and_side_dist(game, ray);
}

int	update_dist_x(t_ray *ray)
{
	ray->dist_to_sidex += ray->dist_deltax;
	ray->grid_x += ray->step_directx;
	if (ray->step_directx == -1)
		return (2);
	else
		return (1);
}

int	update_dist_y(t_ray *ray)
{
	ray->dist_to_sidey += ray->dist_deltay;
	ray->grid_y += ray->step_directy;
	if (ray->step_directy == -1)
		return (3);
	else
		return (4);
}

int	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;
	int	wall_side;

	hit = 0;
	while (hit == 0)
	{
		if (ray->dist_to_sidex < ray->dist_to_sidey)
			wall_side = update_dist_x(ray);
		else
			wall_side = update_dist_y(ray);
		if (game->map.layout[ray->grid_y][ray->grid_x] == '1')
			hit = 1;
	}
	return (wall_side);
}
