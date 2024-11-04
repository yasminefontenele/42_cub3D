/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:48:37 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/04 15:34:57 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
 
int check_surrounding_cells(char **map_tab, int row, int col, int height, int width)
{
    char cell;
	
	cell = map_tab[row][col];
    if (cell == '1' || cell == ' ') 
        return (1);
    if (row <= 0 || row >= height - 1 || col <= 0 || col >= width - 1)
        return (0);
    if (map_tab[row - 1][col] == ' ' || map_tab[row + 1][col] == ' ' ||
        map_tab[row][col - 1] == ' ' || map_tab[row][col + 1] == ' ')
        return (0);
    return (1);
}

int is_valid_player(char cell, int *player_count)
{
    if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
	{
        (*player_count)++;
        if (*player_count > 1)
		{
            printf("Error:\n" MULT_PLAYER "\n");
            return (0);
        }
    }
    return (1);
}

int validate_cell(char **map_tab, int row, int col, int *player_count, int height, int width)
{
    char cell;
	
	cell = map_tab[row][col];
    if (!is_valid_map_char(cell))
	{
        printf("Error:\n" INVALID_CHAR "\n");
        return (0);
    }
    if (!is_valid_player(cell, player_count))
        return (0);
    if ((cell == '0' || cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W') &&
        !check_surrounding_cells(map_tab, row, col, height, width))
        return (0);
    return (1);
}


int validate_map_content(char **map_tab, int height)
{
    int player_count;
    int width;
    size_t row;
	size_t col;

	player_count = 0;
	row = 0;
    while (row < (size_t)height)
	{
        width = ft_strlen(map_tab[row]);
		col = 0;
        while (col < (size_t)width)
		{
            if (!validate_cell(map_tab, row, col, &player_count, height, width))
                return (0);
			col++;
        }
		row++;
    }
    if (player_count != 1)
        return (0);
    return(1);
}


int validate_map(char **map_tab, int height)
{
    if (!validate_map_content(map_tab, height))
        return (0);
    return (1);
}
