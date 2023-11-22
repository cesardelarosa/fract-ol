/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:47:58 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/22 03:43:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // to exclude

#include <stdlib.h>
#include "mlx.h"
#include "params.h"
#include "hooks.h"
#include "draw.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (-*s2);
}

void	args_error(void)
{
	printf("ERROR: arguments not valid\n\n");
	printf("Required first argument options (fractal type):\n");
	printf("\tmandelbrot\n\tjulia\n\tnewton\n\n");
	printf("Optional second argument options (Color):\n");
	printf("\tgrey\n\tred_green\n\tred_blue\n\tgreen_blue\n\trainbow\n");
	exit(0);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		args_error();
	if (ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "mandelbrot"))
		args_error();
}

t_params	start_params(void)
{
	t_params	params;

	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, WIDTH, HEIGHT, "fract-ol");
	params.x_move = 0.0;
	params.y_move = 0.0;
	params.zoom = 1.0;
	return (params);
}

void	run_window(char *fractal)
{
	t_params	params;

	params = start_params();
	mlx_key_hook(params.win, key_hook, &params);
	mlx_mouse_hook(params.win, mouse_hook, &params);
	if (!ft_strcmp(fractal, "mandelbrot"))
		draw_mandelbrot_set(&params);
	if (!ft_strcmp(fractal, "julia"))
		draw_julia_set(&params);
	mlx_loop(params.mlx);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	run_window(argv[1]);
	return (0);
}
