/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 02:05:38 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

void	cleanup(t_vars *vars)
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
	draw(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	old_zoom;

	if (button == MOUSE_UP)
	{
		old_zoom = vars->zoom;
		vars->zoom *= ZOOM_FACTOR;
		vars->x += (x - WIDTH / 2) * ((X_VIEW / (old_zoom * WIDTH))
				- (X_VIEW / (vars->zoom * WIDTH)));
		vars->y += (y - HEIGHT / 2) * ((Y_VIEW / (old_zoom * HEIGHT))
				- (Y_VIEW / (vars->zoom * HEIGHT)));
	}
	else if (button == MOUSE_DOWN)
	{
		old_zoom = vars->zoom;
		vars->zoom /= ZOOM_FACTOR;
		vars->x += (x - WIDTH / 2) * ((X_VIEW / (old_zoom * WIDTH))
				- (X_VIEW / (vars->zoom * WIDTH)));
		vars->y += (y - HEIGHT / 2) * ((Y_VIEW / (old_zoom * HEIGHT))
				- (Y_VIEW / (vars->zoom * HEIGHT)));
	}
	draw(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	cleanup(vars);
	exit(0);
	return (0);
}
