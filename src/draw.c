/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:01:12 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/12/01 13:16:04 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "params.h"
#include "complex_numbers.h"
#include "colors.h"

#define MAX_ITER 50
#define THRESHOLD 4.0

double	norm_dim(double dim, double move, double zoom, int max)
{
	return (zoom * (dim - max * (0.5 + move)) / (max / 4));
}

t_complex	norm_graph(t_complex pixel, t_params *params)
{
	t_complex	z;

	z.x = norm_dim(pixel.x, params->x_move, params->zoom, WIDTH);
	z.y = norm_dim(pixel.y, params->y_move, params->zoom, HEIGHT);
	return (z);
}

void	draw_julia_set(t_params *params)
{
	t_complex	pixel;
	t_complex	z;
	t_complex	c;
	int			i;

	pixel.x = 0;
	while (pixel.x < WIDTH)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			z = norm_graph(pixel, params);
			c.x = -0.7;
			c.y = 0.25;
			i = 0;
			while (i++ <= MAX_ITER && complex_norme(z) < THRESHOLD)
				z = ft_julia(z, c);
			mlx_pixel_put(params->mlx, params->win, pixel.x, pixel.y, color(i));
			pixel.y++;
		}
		pixel.x++;
	}
}

void	draw_mandelbrot_set(t_params *params)
{
	t_complex	pixel;
	t_complex	z;
	t_complex	c;
	int			i;

	pixel.x = 0;
	while (pixel.x < WIDTH)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			c = norm_graph(pixel, params);
			z.x = 0;
			z.y = 0;
			i = 0;
			while (i++ <= MAX_ITER && complex_norme(z) < THRESHOLD)
				z = ft_julia(z, c);
			mlx_pixel_put(params->mlx, params->win, pixel.x, pixel.y, color(i));
			pixel.y++;
		}
		pixel.x++;
	}
}

void	draw_ship_set(t_params *params)
{
	t_complex	pixel;
	t_complex	z;
	t_complex	c;
	int			i;

	pixel.x = 0;
	while (pixel.x < WIDTH)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			c = norm_graph(pixel, params);
			z.x = 0;
			z.y = 0;
			i = 0;
			while (i++ <= MAX_ITER && complex_norme(z) < THRESHOLD)
				z = ft_ship(z, c);
			mlx_pixel_put(params->mlx, params->win, pixel.x, pixel.y, color(i));
			pixel.y++;
		}
		pixel.x++;
	}
}

/*
void	draw(t_params *params, void (*fractal) (), void (*color) ())
{
	fractal(params, color);
}


void	julia(t_params *params, void (*color) ())
{

}
*/
