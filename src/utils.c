/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:26:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/09/06 18:26:11 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	div;

	result = 0;
	sign = 1;
	while (*str && *str != ' ' && *str != '\t')
		str++;
	if (*(++str) == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str++ == '.')
	{
		div = 10;
		while (*str >= '0' && *str <= '9')
		{
			result += sign * (*str++ - '0') / div;
			div *= 10;
		}
	}
	return (result);
}
