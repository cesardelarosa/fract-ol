/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:49:59 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/22 03:16:56 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_ITER 50

int	color(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 550 * i % 255;
	green = 500 * i % 255;
	blue = 450 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}
/*
int	rainbow(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 550 * i % 255;
	green = 500 * i % 255;
	blue = 450 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}

int	blue_green(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 0 * i % 255;
	green = 100 * i % 255;
	blue = 120 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}

int	red_green(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 100 * i % 255;
	green = 120 * i % 255;
	blue = 0 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}

int	red_blue(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 100 * i % 255;
	green = 0 * i % 255;
	blue = 120 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}

int	grey(int i)
{
	int	red;
	int	green;
	int	blue;

	if (i >= MAX_ITER)
		return (0x000000);
	red = 10 * i % 255;
	green = 10 * i % 255;
	blue = 10 * i % 255;
	return ((red << 16) | (green << 8) | blue);
}
*/
