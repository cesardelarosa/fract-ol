/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:49:59 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/18 11:12:59 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consts.h"

int	color(int i)
{
	int	colors[N_COLORS];

	colors[0] = BLACK;
	colors[1] = BLUE;
	colors[2] = YELLOW;
	colors[3] = RED;
	if (i >= MAX_ITER)
		return (colors[0]);
	return (colors[i % N_COLORS]);
}
