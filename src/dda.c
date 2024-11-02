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

void calculate_delta_distance(t_ray *ray)
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

void calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
    if (ray->direc_x < 0)
    {
        ray->step_directx = -1;
        ray->dist_to_sidex = (game->player.pos_x - ray->grid_x) * ray->dist_deltax;
    }
    else
    {
        ray->step_directx = 1;
        ray->dist_to_sidex = (ray->grid_x + 1.0 - game->player.pos_x) * ray->dist_deltax;
    }

    if (ray->direc_y < 0)
    {
        ray->step_directy = -1;
        ray->dist_to_sidey = (game->player.pos_y - ray->grid_y) * ray->dist_deltay;
    }
    else
    {
        ray->step_directy = 1;
        ray->dist_to_sidey = (ray->grid_y + 1.0 - game->player.pos_y) * ray->dist_deltay;
    }
}

void initialize_dda(t_game *game, t_ray *ray)
{
    calculate_delta_distance(ray);
    calculate_step_and_side_dist(game, ray);
}

int perform_dda(t_game *game, t_ray *ray)
{
    int hit;
    int wall_side;
    
    hit = 0;
    wall_side = -1;
    while (hit == 0)
    {
        if (ray->dist_to_sidex < ray->dist_to_sidey)
        {
            ray->dist_to_sidex += ray->dist_deltax;
            ray->grid_x += ray->step_directx;
            if (ray->step_directx == -1)
                wall_side = 2;
            else
                wall_side = 1;
        }
        else
        {
            ray->dist_to_sidey += ray->dist_deltay;
            ray->grid_y += ray->step_directy;
            if (ray->step_directy == -1)
                wall_side = 3;
            else
                wall_side = 4;
        }
        if (game->map.layout[ray->grid_y][ray->grid_x] == '1')
            hit = 1;
    }
    return (wall_side);
}

