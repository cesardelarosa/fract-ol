/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 00:52:21 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

static void	cleanup(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		cleanup(vars);
		exit(0);
	}
	else if (keycode == LEFT_ARROW_KEY)
		vars->x -= 0.1 / vars->zoom;
	else if (keycode == RIGHT_ARROW_KEY)
		vars->x += 0.1 / vars->zoom;
	else if (keycode == DOWN_ARROW_KEY)
		vars->y += 0.1 / vars->zoom;
	else if (keycode == UP_ARROW_KEY)
		vars->y -= 0.1 / vars->zoom;
	else if (keycode == C_KEY)
		vars->color = (vars->color + 1) % N_COLORS;
	else if (keycode == R_KEY)
	{
		vars->x = 0;
		vars->y = 0;
		vars->zoom = 1;
	}
	draw(vars);
	return (0);
}

static void	toggle_fractal(int x, int y, t_vars *vars)
{
	if (vars->fractal == mandelbrot)
	{
		vars->julia_cx = X_VIEW / (vars->zoom * WIDTH) * (x - WIDTH / 2.0)
			+ vars->x;
		vars->julia_cy = Y_VIEW / (vars->zoom * HEIGHT) * (y - HEIGHT / 2.0)
			+ vars->y;
		vars->fractal = julia;
	}
	else if (vars->fractal == julia)
		vars->fractal = mandelbrot;
	vars->zoom = 1;
	vars->x = 0;
	vars->y = 0;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double		old_zoom;
	t_complex	diff;

	if (button == MOUSE_UP)
	{
		old_zoom = vars->zoom;
		vars->zoom *= ZOOM_FACTOR;
		diff.x = (X_VIEW / (old_zoom * WIDTH)) - (X_VIEW / (vars->zoom * WIDTH));
		diff.y = (Y_VIEW / (old_zoom * HEIGHT)) - (Y_VIEW / (vars->zoom * HEIGHT));
		vars->x += (x - WIDTH / 2) * diff.x;
		vars->y += (y - HEIGHT / 2) * diff.y;
	}
	else if (button == MOUSE_DOWN)
	{
		old_zoom = vars->zoom;
		vars->zoom /= ZOOM_FACTOR;
		diff.x = (X_VIEW / (old_zoom * WIDTH)) - (X_VIEW / (vars->zoom * WIDTH));
		diff.y = (Y_VIEW / (old_zoom * HEIGHT)) - (Y_VIEW / (vars->zoom * HEIGHT));
		vars->x += (x - WIDTH / 2) * diff.x;
		vars->y += (y - HEIGHT / 2) * diff.y;
	}
	else if (button == 1)
		toggle_fractal(x, y, vars);
	draw(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	cleanup(vars);
	exit(0);
	return (0);
}
