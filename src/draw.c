/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:17:21 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/17 17:16:12 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include "calc.h"
#include <math.h>

double	julia(t_pixel p, t_vars *vars)
{
	return (calc_fractal(p, vars, init_julia, update_standard));
}

double	mandelbrot(t_pixel p, t_vars *vars)
{
	return (calc_fractal(p, vars, init_mandelbrot, update_standard));
}

double	burning_ship(t_pixel p, t_vars *vars)
{
	return (calc_fractal(p, vars, init_mandelbrot, update_burning_ship));
}

static unsigned int	get_color(double iter, t_vars *vars)
{
	double			t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iter >= MAX_ITER)
		return (0);
	t = iter / MAX_ITER;
	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + vars->color * 30) % 256;
	g = (g + vars->color * 50) % 256;
	b = (b + vars->color * 70) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	draw(t_vars *vars)
{
	t_pixel			p;
	int				offset;
	int				bpp;
	double			i;

	bpp = vars->bpp / 8;
	p.y = 0;
	while (p.y < HEIGHT)
	{
		offset = p.y * vars->sline;
		p.x = 0;
		while (p.x < WIDTH)
		{
			i = vars->fractal(p, vars);
			*((unsigned int *)(vars->data + offset + p.x * bpp))
				= get_color(i, vars);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
