/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:27:45 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/02 18:00:33 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	events_init(t_game *game)
{
	mlx_hook(game->data.win, KeyPress, KeyPressMask, handle_key, game);
	mlx_hook(game->data.win, DestroyNotify, StructureNotifyMask,
		close_window, game);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->layout[i]);
		i++;
	}
	free(map->layout);
	map->layout = NULL;
}

static void	destroy_image(void *mlx, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

int	close_window(t_game *game)
{
	void	*mlx;

	mlx = game->data.mlx;
	if (game->map.layout)
		free_map(&game->map);
	destroy_image(mlx, (void **)&game->texture.north_img);
	destroy_image(mlx, (void **)&game->texture.south_img);
	destroy_image(mlx, (void **)&game->texture.west_img);
	destroy_image(mlx, (void **)&game->texture.east_img);
	if (game->data.win)
	{
		mlx_clear_window(mlx, game->data.win);
		mlx_destroy_window(mlx, game->data.win);
	}
	destroy_image(mlx, (void **)&game->data.img);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	if (keycode == XK_w)
		move_player(game, 'S');
	if (keycode == XK_a)
		move_player(game, 'W');
	if (keycode == XK_Right)
		rotate_player(game, -game->player.rot_sp);
	if (keycode == XK_Left)
		rotate_player(game, game->player.rot_sp);
	if (keycode == XK_s)
		move_player(game, 'N');
	if (keycode == XK_d)
		move_player(game, 'E');
	raycasting(game);
	return (0);
}
