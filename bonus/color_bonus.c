/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:51:54 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 19:51:56 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

static unsigned int	color_scheme_0(double t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static unsigned int	color_scheme_1(double t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			local;

	if (t < 0.5)
	{
		local = t * 2;
		r = (unsigned char)((1 - local) * 128);
		g = (unsigned char)(local * 255);
		b = (unsigned char)(((1 - local) * 128) + (local * 255));
	}
	else
	{
		local = (t - 0.5) * 2;
		r = (unsigned char)(local * 255);
		g = 255;
		b = (unsigned char)((1 - local) * 255);
	}
	return ((r << 16) | (g << 8) | b);
}

static unsigned int	color_scheme_2(double t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(((sin(PI * t) + 1) / 2) * 255);
	g = (unsigned char)(((sin(PI * t + 2.0) + 1) / 2) * 255);
	b = (unsigned char)(((sin(PI * t + 4.0) + 1) / 2) * 255);
	return ((r << 16) | (g << 8) | b);
}

static unsigned int	color_scheme_3(double t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(t * 255);
	g = (unsigned char)(t * t * 255);
	b = (unsigned char)(t * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}

unsigned int	get_color(double iter, t_vars *vars)
{
	if (iter >= MAX_ITER)
		return (0);
	if (vars->color == 0)
		return (color_scheme_0(iter / MAX_ITER));
	else if (vars->color == 1)
		return (color_scheme_1(iter / MAX_ITER));
	else if (vars->color == 2)
		return (color_scheme_2(iter / MAX_ITER));
	return (color_scheme_3(iter / MAX_ITER));
}
