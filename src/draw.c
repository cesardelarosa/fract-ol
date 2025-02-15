/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:17:21 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:32:54 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

int	julia(int x, int y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	z.x = 3.0 / (vars->zoom * WIDTH) * (x - WIDTH / 2.0) + vars->x;
	z.y = 2.0 / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0) + vars->y;
	c.x = vars->julia_cx;
	c.y = vars->julia_cy;
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i++;
	}
	return (i);
}

int	mandelbrot(int x, int y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	z.x = 0;
	z.y = 0;
	c.x = 3.0 / (vars->zoom * WIDTH) * (x - WIDTH / 2.0) + vars->x;
	c.y = 2.0 / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0) + vars->y;
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i++;
	}
	return (i);
}

int	burning_ship(int x, int y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	z.x = 0;
	z.y = 0;
	c.x = 3.0 / (vars->zoom * WIDTH) * (x - WIDTH / 2.0) + vars->x;
	c.y = 2.0 / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0) + vars->y;
	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y < THRESHOLD))
	{
		tmp = z;
		z.x = fabs(tmp.x * tmp.x - tmp.y * tmp.y + c.x);
		z.y = fabs(2 * tmp.x * tmp.y + c.y);
		i++;
	}
	return (i);
}

static unsigned int	get_color(int iter, t_vars *vars)
{
	double			t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iter >= MAX_ITER)
		return (0);
	t = (double)iter / MAX_ITER;
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
	int	x;
	int	y;
	int	iter;
	int	offset;
	int	bpp;

	bpp = vars->bpp / 8;
	y = 0;
	while (y < HEIGHT)
	{
		offset = y * vars->sline;
		x = 0;
		while (x < WIDTH)
		{
			iter = vars->fractal(x, y, vars);
			*((unsigned int *)(vars->data + offset + x * bpp)) = get_color(iter,
					vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
