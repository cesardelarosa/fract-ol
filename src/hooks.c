/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:16:16 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
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

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	old_zoom;
	double	diff_x;
	double	diff_y;

	if (button == MOUSE_UP)
	{
		old_zoom = vars->zoom;
		vars->zoom *= ZOOM_FACTOR;
		diff_x = (3.0 / (old_zoom * WIDTH)) - (3.0 / (vars->zoom * WIDTH));
		diff_y = (2.0 / (old_zoom * HEIGHT)) - (2.0 / (vars->zoom * HEIGHT));
		vars->x += (x - WIDTH / 2) * diff_x;
		vars->y += (y - HEIGHT / 2) * diff_y;
	}
	else if (button == MOUSE_DOWN)
	{
		old_zoom = vars->zoom;
		vars->zoom /= ZOOM_FACTOR;
		diff_x = (3.0 / (old_zoom * WIDTH)) - (3.0 / (vars->zoom * WIDTH));
		diff_y = (2.0 / (old_zoom * HEIGHT)) - (2.0 / (vars->zoom * HEIGHT));
		vars->x += (x - WIDTH / 2) * diff_x;
		vars->y += (y - HEIGHT / 2) * diff_y;
	}
	draw(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
