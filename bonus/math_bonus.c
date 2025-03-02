/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:53 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:05:12 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

/*
 * init_julia:
 *   Maps pixel coordinates to the complex plane for the Julia set.
 *   Formula:
 *     z = zoom_cord * (pixel - (WIDTH/2, HEIGHT/2)) + (x, y)
 *     c = constant from vars->julia
 */
void	init_julia(t_pixel p, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = vars->zoom_cord.x * (p.x - WIDTH / 2.0) + vars->x;
	z->y = vars->zoom_cord.y * (p.y - HEIGHT / 2.0) + vars->y;
	c->x = vars->julia.x;
	c->y = vars->julia.y;
}

/*
 * init_mandelbrot:
 *   Maps pixel coordinates to the complex plane for the Mandelbrot set.
 *   Formula:
 *     z = 0
 *     c = zoom_cord * (pixel - (WIDTH/2, HEIGHT/2)) + (x, y)
 */
void	init_mandelbrot(t_pixel p, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = 0;
	z->y = 0;
	c->x = vars->zoom_cord.x * (p.x - WIDTH / 2.0) + vars->x;
	c->y = vars->zoom_cord.y * (p.y - HEIGHT / 2.0) + vars->y;
}

/*
 * update_standard:
 *   Standard fractal iteration: z = z² + c.
 *   Formula:
 *     z.x = tmp.x² - tmp.y² + c.x
 *     z.y = 2 · tmp.x · tmp.y + c.y
 */
void	update_standard(t_complex *z, t_complex *tmp, t_complex *c)
{
	z->x = tmp->x * tmp->x - tmp->y * tmp->y + c->x;
	z->y = 2 * tmp->x * tmp->y + c->y;
}
