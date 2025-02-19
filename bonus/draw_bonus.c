/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:05:57 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

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

static double	calc_fractal(t_pixel p, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	double		smooth_iter;

	vars->init_func(p, vars, &z, &c);
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		vars->update_func(&z, &tmp, &c);
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
			i = calc_fractal(p, vars);
			*((unsigned int *)(vars->data + offset + p.x * bpp))
				= get_color(i, vars);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
