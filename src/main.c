/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:50:03 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/07/13 17:37:23 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "utils.h"

#define MOUSE_UP 4
#define MOUSE_DOWN 5
#define C_KEY 99
#define R_KEY 114
#define CLOSE_WIN 17
#define ESC_KEY 65307
#define LEFT_ARROW_KEY 65361
#define UP_ARROW_KEY 65362
#define RIGHT_ARROW_KEY 65363
#define DOWN_ARROW_KEY 65364
#define ZOOM_FACTOR 1.2
#define N_COLORS 10

t_vars	read_args(int argc, char **argv)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data = mlx_get_data_addr(vars.img, &vars.bpp, &vars.sline, &vars.end);
	vars.x = 0;
	vars.y = 0;
	vars.zoom = 1;
	vars.fractal = select_fractal(argv[1]);
	if (vars.fractal == NULL)
	{
		perror("Invalid fractal type. Use: julia, mandelbrot, burning_ship");
		exit(EXIT_FAILURE);
	}
	vars.color = 0;
	vars.julia_cx = -0.7;
	vars.julia_cy = 0.27015;
	if (argc == 4)
	{
		vars.julia_cx = ft_atoi(argv[2]);
		vars.julia_cy = ft_atoi(argv[3]);
	}
	return (vars);
}

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
		vars->y = 0;
		vars->x = 0;
		vars->zoom = 1;
	}
	draw(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_UP)
	{
		vars->zoom *= ZOOM_FACTOR;
		vars->x += (x - WIDTH / 2) / (vars->zoom * WIDTH);
		vars->y += (y - HEIGHT / 2) / (vars->zoom * HEIGHT);
	}
	else if (button == MOUSE_DOWN)
	{
		vars->zoom /= ZOOM_FACTOR;
		vars->x += (x - WIDTH / 2) / (vars->zoom * WIDTH);
		vars->y += (y - HEIGHT / 2) / (vars->zoom * HEIGHT);
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && argc != 4)
	{
		perror("Usage: ./fractol <fractal_type> [<julia_cx> <julia_cy>]\n"
			"<fractal_type> = {julia, mandelbrot, burning_ship}");
		exit(EXIT_FAILURE);
	}
	vars = read_args(argc, argv);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, CLOSE_WIN, 0, close_window, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	draw(&vars);
	ft_printf("Controls:\n"
		"C -> change color\n"
		"R -> reset position\n"
		"ARROWS -> move\n"
		"MOUSE_WHEEL -> zoom\n");
	mlx_loop(vars.mlx);
	return (0);
}