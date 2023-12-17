/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:05:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/12/01 13:16:06 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "params.h"
#include "draw.h"

#define ESC_KEY 53

#define LEFT_ARROW_KEY 123
#define RIGHT_ARROW_KEY 124
#define DOWN_ARROW_KEY 125
#define UP_ARROW_KEY 126

#define C_KEY 8
#define R_KEY 15

#define MOUSE_UP 4
#define MOUSE_DOWN 5

int	close_window_hook(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	exit(0);
}

int	key_hook(int keycode, t_params *params)
{
	if (keycode == ESC_KEY)
		close_window_hook(params);
	else if (keycode == LEFT_ARROW_KEY)
		params->x_move += 0.1;
	else if (keycode == RIGHT_ARROW_KEY)
		params->x_move -= 0.1;
	else if (keycode == DOWN_ARROW_KEY)
		params->y_move -= 0.1;
	else if (keycode == UP_ARROW_KEY)
		params->y_move += 0.1;
	/*else if (keycode == C_KEY)
		change_color();
	else if (keycode == R_KEY)
		reset_draw();*/
	mlx_clear_window(params->mlx, params->win);
	draw_julia_set(params);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_params *params)
{
	if (button == MOUSE_UP)
	{
		params->zoom *= ZOOM_FACTOR;
		params->x_move += (x - WIDTH / 2.0) / WIDTH * ZOOM_FACTOR;
		params->y_move += (y - HEIGHT / 2.0) / HEIGHT * ZOOM_FACTOR;
	}
	else if (button == MOUSE_DOWN)
	{
		params->zoom /= ZOOM_FACTOR;
		params->x_move -= (x - WIDTH / 2.0) / WIDTH * ZOOM_FACTOR;
		params->y_move -= (y - HEIGHT / 2.0) / HEIGHT * ZOOM_FACTOR;
	}
	mlx_clear_window(params->mlx, params->win);
	draw_julia_set(params);
	return (0);
}
