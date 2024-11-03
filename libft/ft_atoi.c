/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <emencova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:12:52 by emencova          #+#    #+#             */
/*   Updated: 2024/11/03 13:03:36 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../inc/cub3d.h"

int	process_sign_and_whitespace(const char **nptr)
{
	int		sign;

	sign = 1;
	while ((**nptr <= 13 && **nptr >= 9) || (**nptr == 32))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
		{
			printf("Error:\n" COLOR_RANGE "\n");
			exit(1);
		}
		(*nptr)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int			res;
	int			sign;	

	sign = process_sign_and_whitespace(&nptr);
	res = 0;
	while ((*nptr >= '0' && *nptr <= '9') || *nptr == ',')
	{
		if (*nptr == ',')
			nptr++;
		else
		{
			res = res * 10 + (*nptr - '0');
			nptr++;
		}
	}
	return (res * sign);
}
