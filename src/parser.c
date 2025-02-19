/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 16:31:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void	select_fractal(char *str, t_vars *vars)
{
	size_t			i;
	size_t			n;
	const t_fractal	fractals[] = {
	{"julia", init_julia, update_standard},
	{"mandelbrot", init_mandelbrot, update_standard},
	{"burning_ship", init_mandelbrot, update_burning_ship},
	{"multibrot", init_mandelbrot, update_multibrot},
	{"tricorn", init_mandelbrot, update_tricorn},
	{"celtic", init_mandelbrot, update_celtic},
	{"buffalo", init_mandelbrot, update_buffalo},
	};

	n = sizeof(fractals) / sizeof(fractals[0]);
	i = 0;
	while (i < n)
	{
		if (ft_strcmp(str, (char *)fractals[i].name) == 0)
		{
			vars->init_func = fractals[i].init_func;
			vars->update_func = fractals[i].update_func;
			return ;
		}
		i++;
	}
	ft_error("Invalid fractal type. Use: " FRACTALS ", " FRACTALS2 "\n");
}

t_vars	parser(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && (argc != 4 || ft_strncmp(argv[1], "julia", 6)))
	{
		ft_error("Usage: ./fractol <fractal_type> [<julia_cx> <julia_cy>]"
			"\n<fractal_type> = " FRACTALS ", " FRACTALS2 "\n");
	}
	select_fractal(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data = mlx_get_data_addr(vars.img, &vars.bpp, &vars.sline, &vars.end);
	vars.x = 0;
	vars.y = 0;
	vars.zoom = 1;
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
