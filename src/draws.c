/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:14:46 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/03 12:58:19 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_cell_color(char cell, t_game *game)
{
	int	color;

	if (cell == '2')
		color = game->ceiling_color;
	else
		color = game->floor_color;
	return (color);
}

void	draw_floor_and_ceiling(t_game *game, int x, t_ray *ray)
{
	int	y;

	game->floor_color = get_cell_color('1', game);
	game->ceiling_color = get_cell_color('2', game);
	y = 0;
	while (y < ray->start_draw)
	{
		mlx_pixel_put(game->data.mlx, game->data.win, x, y,
			game->ceiling_color);
		y++;
	}
	y = ray->end_draw;
	while (y < HEIGHT)
	{
		mlx_pixel_put(game->data.mlx, game->data.win, x, y, game->floor_color);
		y++;
	}
}

int	calculate_texture_x(t_game *game, double wallx)
{
	int	text_x;

	text_x = (int)(wallx * game->texture.width);
	if (text_x < 0)
		text_x = 0;
	if (text_x >= game->texture.width)
		text_x = game->texture.width - 1;
	return (text_x);
}

int	get_texture_color(t_game *game, void *texture, int text_x, int text_y)
{
	int		bpp;
	int		size_line;
	char	*data_addr;
	int		endian;

	data_addr = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	if (text_y >= 0 && text_y < game->texture.height)
		return (*(int *)(data_addr + text_y * size_line + text_x * (bpp / 8)));
	return (0);
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray, void *texture)
{
	int	y;
	int	text_x;
	int	line_height;
	int	color;
	int	text_y;

	y = ray->start_draw;
	text_x = calculate_texture_x(game, ray->wallx);
	line_height = ray->end_draw - ray->start_draw;
	while (y <= ray->end_draw)
	{
		text_y = ((y - ray->start_draw) * game->texture.height) / line_height;
		color = get_texture_color(game, texture, text_x, text_y);
		if (y >= 0 && y < HEIGHT)
			mlx_pixel_put(game->data.mlx, game->data.win, x, y, color);
		y++;
	}
}
