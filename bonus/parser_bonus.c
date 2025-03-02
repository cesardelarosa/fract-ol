/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:07:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:07:56 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static t_fractal	select_fractal(char *str)
{
	size_t			i;
	size_t			n;
	const t_fractal	fractals[] = {
	{"julia", init_julia, update_standard, 0},
	{"mandelbrot", init_mandelbrot, update_standard, 0},
	{"burning_ship", init_mandelbrot, update_burning_ship, 1},
	{"multibrot", init_mandelbrot, update_multibrot, 1},
	{"tricorn", init_mandelbrot, update_tricorn, 1},
	{"celtic", init_mandelbrot, update_celtic, 1},
	{"buffalo", init_mandelbrot, update_buffalo, 1},
	};

	n = sizeof(fractals) / sizeof(fractals[0]);
	i = -1;
	while (++i < n)
	{
		if (ft_strcmp(str, (char *)fractals[i].name) == 0)
			return (fractals[i]);
	}
	ft_error("Invalid fractal type. Use: " FRACTALS ", " FRACTALS_BONUS "\n");
	return ((t_fractal){NULL, NULL, NULL, -1});
}

t_vars	parser(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && (argc != 4 || ft_strncmp(argv[1], "julia", 6)))
	{
		ft_error("Usage: ./fractol <fractal_type> [<julia_cx> <julia_cy>]\n"
			"<fractal_type> = " FRACTALS ", " FRACTALS_BONUS "\n");
	}
	vars.fractal = select_fractal(argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT + INFO_HEIGHT, "fractol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data = mlx_get_data_addr(vars.img, &vars.bpp, &vars.sline, &vars.end);
	vars.x = 0;
	vars.y = 0;
	vars.zoom = 1;
	vars.color = 0;
	vars.julia.x = -0.7;
	vars.julia.y = 0.27015;
	vars.info_update = 1;
	if (argc == 4)
	{
		vars.julia.x = ft_atof(argv[2]);
		vars.julia.y = ft_atof(argv[3]);
	}
	return (vars);
}
