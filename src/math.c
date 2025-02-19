/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:29:06 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 15:57:04 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_julia(t_pixel p, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = X_VIEW / (vars->zoom * WIDTH) * (p.x - WIDTH / 2.0) + vars->x;
	z->y = Y_VIEW / (vars->zoom * HEIGHT) * (p.y - HEIGHT / 2.0) + vars->y;
	c->x = vars->julia.x;
	c->y = vars->julia.y;
}

void	init_mandelbrot(t_pixel p, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = 0;
	z->y = 0;
	c->x = X_VIEW / (vars->zoom * WIDTH) * (p.x - WIDTH / 2.0) + vars->x;
	c->y = Y_VIEW / (vars->zoom * HEIGHT) * (p.y - HEIGHT / 2.0) + vars->y;
}

void	update_standard(t_complex *z, t_complex *tmp, t_complex *c)
{
	z->x = tmp->x * tmp->x - tmp->y * tmp->y + c->x;
	z->y = 2 * tmp->x * tmp->y + c->y;
}
