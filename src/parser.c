/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:04:05 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/02 15:20:58 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"

int	parse_rgb(const char *str, t_color *color)
{
	char	**rgb_split;
	int		r;
	int		g;
	int		b;
	int		rgb;

	rgb_split = ft_split(str, ',');
	if (!rgb_split || !rgb_split[0] || !rgb_split[1] || !rgb_split[2])
	{
		printf("Error:\n"COLOR_FORMAT"\n");
		exit(1);
	}
	r = ft_atoi(rgb_split[0]);
	g = ft_atoi(rgb_split[1]);
	b = ft_atoi(rgb_split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error:\n"COLOR_RANGE"\n");
		free_split(rgb_split);
		exit(1);
	}
	rgb = (r << 16) | (g << 8) | b;
	color->rgb = rgb;
	free_split(rgb_split);
	return (color->rgb);
}

int	parse_color(const char *line, t_color *color)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split[0] && split[1])
		color->rgb = parse_rgb(split[1], color);
	free_split(split);
	return (color->rgb);
}

void	check_texture_path(void *texture_img, const char *texture_path)
{
	if (!texture_img)
	{
		printf("Error:\n"WRONG_TEX" <%s>\n", texture_path);
		exit(1);
	}
}

void	clean_texture_paths(t_game *game)
{
	game->texture.north[ft_strlen(game->texture.north) - 1] = '\0';
	game->texture.south[ft_strlen(game->texture.south) - 1] = '\0';
	game->texture.west[ft_strlen(game->texture.west) - 1] = '\0';
	game->texture.east[ft_strlen(game->texture.east) - 1] = '\0';
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	clean_texture_paths(game);
	game->texture.north_img = mlx_xpm_file_to_image(game->data.mlx,
			game->texture.north, &width, &height);
	if (!game->texture.north_img)
		check_texture_path(game->texture.north_img, game->texture.north);
	game->texture.south_img = mlx_xpm_file_to_image(game->data.mlx,
			game->texture.south, &width, &height);
	if (!game->texture.south_img)
		check_texture_path(game->texture.south_img, game->texture.south);
	game->texture.west_img = mlx_xpm_file_to_image(game->data.mlx,
			game->texture.west, &width, &height);
	if (!game->texture.west_img)
		check_texture_path(game->texture.west_img, game->texture.west);
	game->texture.east_img = mlx_xpm_file_to_image(game->data.mlx,
			game->texture.east, &width, &height);
	if (!game->texture.east_img)
		check_texture_path(game->texture.east_img,
			game->texture.east);
	game->texture.width = width;
	game->texture.height = height;
	free_texture(game);
}
