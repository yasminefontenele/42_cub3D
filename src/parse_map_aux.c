/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:56:38 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/03 12:05:14 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*trim_whitespace(char *str)
{
	char	*end;

	while (my_isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && my_isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

void	allocate_map_row(char **row, int width)
{
	*row = malloc((width + 1) * sizeof(char));
	if (*row == NULL)
	{
		printf("Error\n Failed to allocate memory for map layout row\n");
		exit(EXIT_FAILURE);
	}
	(*row)[width] = '\0';
}

void	allocate_empty_row(char *map_row, int width)
{
	int	k;

	k = 0;
	while (k < width)
	{
		map_row[k] = ' ';
		k++;
	}
	map_row[width] = '\0';
}

void	allocate_map_layout(t_map *map)
{
	map->layout = malloc(map->height * sizeof(char *));
	if (map->layout == NULL)
	{
		printf("Error\n Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}
