/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliskam <eliskam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:25:41 by emencova          #+#    #+#             */
/*   Updated: 2024/11/03 10:13:47 by eliskam          ###   ########.fr       */
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

int	allocate_map_layout(t_map *map)
{
	int	j;

	j = 0;
	map->layout = malloc(sizeof(char *) * (map->height + 1));
	if (!map->layout)
		return (0);
	while (j < map->height)
	{
		map->layout[j] = malloc(sizeof(char) * (map->width + 1));
		if (!map->layout[j])
			return (0);
		j++;
	}
	map->layout[map->height] = NULL;
	return (1);
}

void	fill_map_content(char **file_lines, t_map *map, int map_start)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			if (file_lines[map_start + j][k] != '\0'
				&& file_lines[map_start + j][k] != '\n')
				map->layout[j][k] = file_lines[map_start + j][k];
			else
				map->layout[j][k] = ' ';
			k++;
		}
		map->layout[j][k] = '\0';
		j++;
	}
}


void	fill_map_layout(char **file_lines, t_map *map, int map_start)
{
	if (!allocate_map_layout(map))
		return ;
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
