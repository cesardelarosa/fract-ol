/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:53:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 02:53:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "complex.h"
#include "vars.h"
#include "bonus.h"

#define MAX_ITER_BONUS 100
#define THRESHOLD_BONUS 4.0

int	burning_ship(int x, int y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	z.x = 0;
	z.y = 0;
	c.x = 1.5 * (x - WIDTH / 2.0) / (0.5 * vars->zoom * WIDTH) + vars->x;
	c.y = (y - HEIGHT / 2.0) / (0.5 * vars->zoom * HEIGHT) + vars->y;
	i = 0;
	while (z.x * z.x + z.y * z.y < THRESHOLD_BONUS && i < MAX_ITER_BONUS)
	{
		tmp = z;
		z.x = fabs(tmp.x * tmp.x - tmp.y * tmp.y + c.x);
		z.y = fabs(2 * tmp.x * tmp.y + c.y);
		i++;
	}
	return (i);
}

void	draw_bonus(t_vars *vars)
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
			if (i >= MAX_ITER_BONUS)
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
