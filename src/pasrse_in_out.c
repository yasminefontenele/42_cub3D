/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasrse_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:30 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/02 16:50:32 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	open_and_allocate_file(const char *filename, char ***file, int *nbr_line)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	*nbr_line = count_lines(filename);
	if (*nbr_line == -1)
		return (-1);
	*file = malloc(sizeof(char *) * (*nbr_line + 1));
	if (!*file)
		return (-1);
	if (fd == -1)
	{
		free(*file);
		*file = NULL;
	}
	return (fd);
}

void	read_lines_from_file(int fd, char **file, int nbr_line)
{
	int		i;
	char	*line;

	i = 0;
	while (nbr_line > 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		file[i++] = line;
		nbr_line--;
	}
	file[i] = NULL;
}

char	**read_file_cub(const char *filename)
{
	char	**file;
	int		fd;
	int		nbr_line;

	fd = open_and_allocate_file(filename, &file, &nbr_line);
	if (fd == -1)
		return (NULL);
	read_lines_from_file(fd, file, nbr_line);
	close(fd);
	return (file);
}

void	process_file_lines(char **file_lines, t_game *game)
{
	int	i;

	i = 0;
	while (file_lines[i])
	{
		if (ft_strncmp(file_lines[i], "F", 1) == 0)
			game->floor_color = parse_color(file_lines[i], &game->color);
		else if (ft_strncmp(file_lines[i], "C", 1) == 0)
			game->ceiling_color = parse_color(file_lines[i], &game->color);
		else if (ft_strncmp(file_lines[i], "NO", 2) == 0)
			game->texture.north = ft_strtrim(file_lines[i] + 2, " ");
		else if (ft_strncmp(file_lines[i], "SO", 2) == 0)
			game->texture.south = ft_strtrim(file_lines[i] + 2, " ");
		else if (ft_strncmp(file_lines[i], "WE", 2) == 0)
			game->texture.west = ft_strtrim(file_lines[i] + 2, " ");
		else if (ft_strncmp(file_lines[i], "EA", 2) == 0)
			game->texture.east = ft_strtrim(file_lines[i] + 2, " ");
		i++;
	}
}

void	load_map(const char *filename, t_game *game)
{
	char	**file_lines;

	file_lines = read_file_cub(filename);
	if (!file_lines)
	{
		printf("MAP_FILE\n");
		return ;
	}
	if (!initialize_game_data(game))
	{
		free_file_lines(file_lines);
		exit(1);
	}
	parse_map(file_lines, &game->map);
	parse_player(&game->map, game);
	process_file_lines(file_lines, game);
	load_textures(game);
	free_file_lines(file_lines);
}
