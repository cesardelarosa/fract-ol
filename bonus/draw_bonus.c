/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 20:59:40 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

static double	calc_fractal(t_pixel p, t_vars *vars)
{
	double		i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	double		r2;

	vars->fractal.init_func(p, vars, &z, &c);
	r2 = z.x * z.x + z.y * z.y;
	i = -1;
	while (++i < MAX_ITER && r2 < THRESHOLD)
	{
		tmp = z;
		vars->fractal.update_func(&z, &tmp, &c);
		r2 = z.x * z.x + z.y * z.y;
	}
	if (r2 < THRESHOLD)
		return (i);
	return (i + 1 - log(log(r2) / LOG2) / LOG2);
}

void	draw(t_vars *vars)
{
	unsigned int	*pixel;
	t_pixel			p;

	vars->zoom_cord.x = X_VIEW / (vars->zoom * WIDTH);
	vars->zoom_cord.y = Y_VIEW / (vars->zoom * HEIGHT);
	p.y = -1;
	while (++p.y < HEIGHT)
	{
		pixel = (unsigned int *)(vars->data + p.y * vars->sline);
		p.x = -1;
		while (++p.x < WIDTH)
			pixel[p.x] = get_color(calc_fractal(p, vars), vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->info_update)
		display_info(vars);
}
