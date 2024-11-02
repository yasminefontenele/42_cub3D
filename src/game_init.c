/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:10:04 by emencova          #+#    #+#             */
/*   Updated: 2024/11/02 17:07:28 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	game_init(t_game *game)
{
	game->data.win = mlx_new_window(game->data.mlx, \
			WIDTH, HEIGHT, "Cub3D");
	if (!game->data.win)
	{
		mlx_destroy_display(game->data.mlx);
		free(game->data.mlx);
		exit(1);
	}
	game->data.img = mlx_new_image(game->data.mlx, WIDTH, HEIGHT);
	if (!game->data.img)
	{
		mlx_destroy_window(game->data.mlx, game->data.win);
		mlx_destroy_display(game->data.mlx);
		free(game->data.mlx);
		exit(1);
	}
	game->data.addr = mlx_get_data_addr(game->data.img, \
						&game->data.bits_per_pixel, \
						&game->data.line_length, &game->data.endian);
	render_frame(game);
	raycasting(game);
	events_init(game);
	mlx_loop(game->data.mlx);
}
