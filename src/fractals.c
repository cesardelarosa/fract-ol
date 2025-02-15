/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:13:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 12:24:45 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_julia(int x, int y, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = 3.0 / (vars->zoom * WIDTH) * (x - WIDTH / 2.0) + vars->x;
	z->y = 2.0 / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0) + vars->y;
	c->x = vars->julia_cx;
	c->y = vars->julia_cy;
}

void	init_mandelbrot(int x, int y, t_vars *vars, t_complex *z, t_complex *c)
{
	z->x = 0;
	z->y = 0;
	c->x = 3.0 / (vars->zoom * WIDTH) * (x - WIDTH / 2.0) + vars->x;
	c->y = 2.0 / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0) + vars->y;
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

double	calc_fractal(int x, int y, t_vars *vars,
		void (*init_func)(int, int, t_vars*, t_complex*, t_complex*),
		void (*update_func)(t_complex*, t_complex*, t_complex*))
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	double		smooth_iter;

	init_func(x, y, vars, &z, &c);
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		update_func(&z, &tmp, &c);
		i++;
	}
	if (i < MAX_ITER)
	{
		double log_zn = log(z.x * z.x + z.y * z.y) / 2.0;
		double nu = log(log_zn / log(2)) / log(2);
		smooth_iter = i + 1 - nu;
	}
	else
		smooth_iter = i;
	return (smooth_iter);
}
