/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:49:10 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 02:49:42 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "complex.h"
#include "vars.h"

#define MAX_ITER 100
#define THRESHOLD 3.0

int	julia(int x, int y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	z.x = 1.5 * (x - WIDTH / 2) / (0.5 * vars->zoom * WIDTH) + vars->x;
	z.y = (y - HEIGHT / 2) / (0.5 * vars->zoom * HEIGHT) + vars->y;
	c.x = vars->julia_cx;
	c.y = vars->julia_cy;
	i = 0;
	while (z.x * z.x + z.y * z.y < THRESHOLD && i++ < MAX_ITER)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
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
	c.x = 1.5 * (x - WIDTH / 2) / (vars->zoom * WIDTH / 2) + vars->x;
	c.y = (y - HEIGHT / 2) / (vars->zoom * HEIGHT / 2) + vars->y;
	i = 0;
	while (z.x * z.x + z.y * z.y < THRESHOLD && i++ < MAX_ITER)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
	}
	return (i);
}

int	(*select_fractal(char *str))(int x, int y, t_vars *vars)
{
	if (!ft_strncmp(str, "julia", 6))
		return (julia);
	if (!ft_strncmp(str, "mandelbrot", 11))
		return (mandelbrot);
	return (NULL);
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;
	int	i;
	int	n;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			i = vars->fractal(x, y, vars);
			if (i >= MAX_ITER)
				i = 0;
			i *= vars->color + 1;
			n = (x * (vars->bpp / 8)) + (y * vars->sline);
			vars->data[n] = 32 * i % 256;
			vars->data[n + 1] = 48 * i % 256;
			vars->data[n + 2] = 40 * i % 256;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
