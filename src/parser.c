/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:14 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static double	(*select_fractal(char *str))(t_pixel p, t_vars *vars)
{
	if (!ft_strncmp(str, "julia", 6))
		return (julia);
	if (!ft_strncmp(str, "mandelbrot", 11))
		return (mandelbrot);
	if (!ft_strncmp(str, "burning_ship", 13))
		return (burning_ship);
	return (NULL);
}

static t_vars	vars_init(int argc, char **argv)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data = mlx_get_data_addr(vars.img, &vars.bpp, &vars.sline, &vars.end);
	vars.x = 0;
	vars.y = 0;
	vars.zoom = 1;
	vars.fractal = select_fractal(argv[1]);
	if (vars.fractal == NULL)
	{
		perror("Invalid fractal type. Use: julia, mandelbrot, burning_ship");
		cleanup(&vars);
		exit(EXIT_FAILURE);
	}
	vars.color = 0;
	vars.julia.x = -0.7;
	vars.julia.y = 0.27015;
	if (argc == 4)
	{
		vars.julia.x = ft_atof(argv[2]);
		vars.julia.y = ft_atof(argv[3]);
	}
	return (vars);
}

t_vars	read_args(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && (argc != 4 || ft_strncmp(argv[1], "julia", 6)))
	{
		perror("Usage: ./fractol <fractal_type> [<julia_cx> <julia_cy>]\n"
			"<fractal_type> = {julia, mandelbrot, burning_ship}");
		exit(EXIT_FAILURE);
	}
	vars = vars_init(argc, argv);
	return (vars);
}
