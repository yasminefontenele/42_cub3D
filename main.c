/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:29:05 by emencova          #+#    #+#             */
/*   Updated: 2024/11/02 13:47:10 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int	validate_input(t_map *map, char **av)
{
	if (validate_map(map->layout, map->height) == 0)
	{
		printf("Error:\n"MAP_INVALID"\n");
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		printf("Error:\n"WRONG_EXT"\n");
		return (0);
	}
	return (1);
}

void	free_img(t_game *game)
{
	if (game->texture.north_img)
		mlx_destroy_image(game->data.mlx, game->texture.north_img);
	if (game->texture.south_img)
		mlx_destroy_image(game->data.mlx, game->texture.south_img);
	if (game->texture.west_img)
		mlx_destroy_image(game->data.mlx, game->texture.west_img);
	if (game->texture.east_img)
		mlx_destroy_image(game->data.mlx, game->texture.east_img);
}

void display_controls(void)
{
    printf(CYAN " ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \n"RESET);
    printf(CYAN"██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n"RESET);
    printf(CYAN"██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n"RESET);
    printf(CYAN"██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n"RESET);
    printf(CYAN"╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n"RESET);
    printf(CYAN" ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \n"RESET);
    printf(MAGENTA "\tW" RESET ": move forward\t");
    printf(MAGENTA "\tS" RESET ": move backward\n");
    printf(MAGENTA "\tA" RESET ": move left\t");
    printf(MAGENTA "\tD" RESET ": move right\n");
    printf(MAGENTA "\t<" RESET ": rotate left\t");
    printf(MAGENTA "\t>" RESET ": rotate right\n");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Error:\n"INVALID_AC"\n");
		exit (1);
	}
	//display_controls();
	ft_memset(&game, 0, sizeof(t_game));
	load_map(av[1], &game);
	if (!validate_input(&game.map, av))
	{
		close_window(&game);
		return (1);
	}
	game_init(&game);
	return (0);
}
