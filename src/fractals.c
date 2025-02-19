/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:13:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 01:43:12 by cde-la-r         ###   ########.fr       */
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

void	update_burning_ship(t_complex *z, t_complex *tmp, t_complex *c)
{
	z->x = fabs(tmp->x * tmp->x - tmp->y * tmp->y + c->x);
	z->y = fabs(2 * tmp->x * tmp->y + c->y);
}

double	calc_fractal(t_pixel p, t_vars *vars,
		void (*init_func)(t_pixel, t_vars*, t_complex*, t_complex*),
		void (*update_func)(t_complex*, t_complex*, t_complex*))
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	double		smooth_iter;

	init_func(p, vars, &z, &c);
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		update_func(&z, &tmp, &c);
		i++;
	}
	if (i < MAX_ITER)
	{
		smooth_iter = i + 1
			- log(log(z.x * z.x + z.y * z.y) / 2.0 / log(2)) / log(2);
	}
	else
		smooth_iter = i;
	return (smooth_iter);
}
