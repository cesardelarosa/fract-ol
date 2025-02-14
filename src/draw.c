/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:37:42 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 10:42:44 by cesi             ###   ########.fr       */
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

int	(*select_fractal(char *str))(int x, int y, t_vars *vars)
{
	if (!ft_strncmp(str, "julia", 6))
		return (julia);
	if (!ft_strncmp(str, "mandelbrot", 11))
		return (mandelbrot);
	if (!ft_strncmp(str, "burning_ship", 13))
		return (burning_ship);
	return (NULL);
}

void	draw(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		offset;
	int		bpp;

	bpp = vars->bpp / 8;
	y = 0;
	while (y < HEIGHT)
	{
		offset = y * vars->sline;
		x = 0;
		while (x < WIDTH)
		{
			i = vars->fractal(x, y, vars);
			if (i >= MAX_ITER)
				i = 0;
			i *= (vars->color + 1);
			vars->data[offset + x * bpp] = (unsigned char)(32 * i % 256);
			vars->data[offset + x * bpp + 1] = (unsigned char)(48 * i % 256);
			vars->data[offset + x * bpp + 2] = (unsigned char)(40 * i % 256);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
