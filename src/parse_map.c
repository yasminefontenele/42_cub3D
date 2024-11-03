/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:25:41 by emencova          #+#    #+#             */
/*   Updated: 2024/11/03 12:03:06 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_map_dimensions(char **file_lines, t_map *map)
{
	int	i;
	int	max_width;
	int	map_start;
	int	current_width;

	i = 0;
	max_width = 0;
	while (file_lines[i] && !(file_lines[i][0] == '1'
		|| file_lines[i][0] == '0'))
		i++;
	map_start = i;
	while (file_lines[i] && (file_lines[i][0] == '1'
		|| file_lines[i][0] == '0'))
	{
		current_width = ft_strlen(file_lines[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	map->height = i - map_start;
	map->width = max_width;
}

void	fill_map_row_content(char *trimmed_line, char *map_row, int width)
{
	int	trimmed_length;
	int	k;

	k = 0;
	trimmed_length = ft_strlen(trimmed_line);
	while (k < width)
	{
		if (k < trimmed_length)
			map_row[k] = trimmed_line[k];
		else
			map_row[k] = ' ';
		k++;
	}
}

void	fill_map_content(char **file_lines, t_map *map, int map_start)
{
	int		j;
	char	*trimmed_line;

	j = 0;
	while (j < map->height)
	{
		if (file_lines[map_start + j] != NULL)
		{
			trimmed_line = trim_whitespace(file_lines[map_start + j]);
			allocate_map_row(&map->layout[j], map->width);
			fill_map_row_content(trimmed_line, map->layout[j], map->width);
		}
		else
		{
			allocate_map_row(&map->layout[j], map->width);
			allocate_empty_row(map->layout[j], map->width);
		}
		j++;
	}
}

void	fill_map_layout(char **file_lines, t_map *map, int map_start)
{
	allocate_map_layout(map);
	fill_map_content(file_lines, map, map_start);
}

void	parse_map(char **file_lines, t_map *map)
{
	int	map_start;

	map_start = 0;
	get_map_dimensions(file_lines, map);
	while (file_lines[map_start] && !(file_lines[map_start][0] == '1'
		|| file_lines[map_start][0] == '0'))
		map_start++;
	fill_map_layout(file_lines, map, map_start);
}
