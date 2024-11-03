/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:47:19 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/03 12:08:49 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_file_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_texture(t_game *game)
{
	free(game->texture.north);
	free(game->texture.south);
	free(game->texture.east);
	free(game->texture.west);
}

void	free_trimmed(char **file_lines)
{
	int	i;

	i = 0;
	while (file_lines[i])
	{
		free(file_lines[i]);
		i++;
	}
	free(file_lines);
}

void	free_textures(t_game *game)
{
	if (game->texture.north)
	{
		mlx_destroy_image(game->data.mlx, game->texture.north);
		free(game->texture.north);
	}
	if (game->texture.south)
	{
		mlx_destroy_image(game->data.mlx, game->texture.south);
		free(game->texture.south);
	}
	if (game->texture.west)
	{
		mlx_destroy_image(game->data.mlx, game->texture.west);
		free(game->texture.west);
	}
	if (game->texture.east)
	{
		free(game->texture.east);
		mlx_destroy_image(game->data.mlx, game->texture.east);
	}
	free_img(game);
}
