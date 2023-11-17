/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:47:58 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/17 20:43:44 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#define WIDTH 500
#define HEIGHT 500

#define ESC_KEY 53
#define LEFT_ARROW_KEY 123
#define RIGHT_ARROW_KEY 124
#define DOWN_ARROW_KEY 125
#define UP_ARROW_KEY 126

#define MOUSE_UP 4
#define MOUSE_DOWN 5

#define CLOSE_WIN 17

#define MAX_ITER 50
#define THRESHOLD 4.0

#define N_COLORS 5
#define BLACK 0x000000
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define ORANGE 0xFFA500
#define RED 0xFF0000

#define ZOOM_FACTOR 1.2

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

double		complex_norme(t_complex z);
t_complex	ft_julia(t_complex z, t_complex c);

typedef struct s_params
{
	void	*mlx;
	void	*win;
	double	x_move;
	double	y_move;
	double	zoom;
}	t_params;

void		draw_julia_set(t_params *params);

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
	mlx_clear_window(params->mlx, params->win);
	draw_julia_set(params);
	return (0);
}

int	julia_color(int i)
{
	int	colors[N_COLORS];

	colors[0] = BLACK;
	colors[1] = BLUE;
	colors[2] = YELLOW;
	colors[3] = ORANGE;
	colors[4] = RED;
	if (i == MAX_ITER)
		return (colors[0]);
	return (colors[i % N_COLORS]);
}

t_complex	norm_graph(t_complex pixel, t_params *params)
{
	t_complex	z;

	z.x = (pixel.x - WIDTH * (0.5 + params->x_move)) / (WIDTH * 0.25);
	z.y = (pixel.y - HEIGHT * (0.5 + params->y_move)) / (HEIGHT * 0.25);
	return (z);
}

/*
int	mouse_hook(int	button, int x, int y, t_params *params)
{
	if  (button == MOUSE_UP)
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
*/

void	draw_julia_set(t_params *params)
{
	t_complex	pixel;
	t_complex	z;
	t_complex	c;
	int			i;

	pixel.x = 0;
	while (pixel.x < WIDTH)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			z = norm_graph(pixel, params);
			c.x = -0.7;
			c.y = 0.25;
			i = 0;
			while (i++ < MAX_ITER && complex_norme(z) < THRESHOLD)
				z = ft_julia(z, c);
			mlx_pixel_put(params->mlx, params->win, pixel.x, pixel.y, julia_color(i));
			pixel.y++;
		}
		pixel.x++;
	}
}

int	main(void)
{
	t_params	params;

	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, WIDTH, HEIGHT, "fract-ol");
	params.x_move = 0.0;
	params.y_move = 0.0;
	mlx_key_hook(params.win, key_hook, &params);
	mlx_hook(params.win, CLOSE_WIN, 0, close_window_hook, &params);
//	mlx_mouse_hook(params.win, mouse_hook, &params);
	draw_julia_set(&params);
	mlx_loop(params.mlx);
	return (0);
}
