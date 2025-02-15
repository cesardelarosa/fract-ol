/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:16:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:16:59 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

int	(*select_fractal(char *str))(int x, int y, t_vars *vars)
{
	if (!ft_strncmp(str, "julia", 6))
		return (julia);
	if (!ft_strncmp(str, "mandelbrot", 11))
		return (mandelbrot);
	if (!ft_strncmp(str, "burning_ship", 13))
		return (burning_ship);
	return (NULL);
}

t_vars	read_args(int argc, char **argv)
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
		exit(EXIT_FAILURE);
	}
	vars.color = 0;
	vars.julia_cx = -0.7;
	vars.julia_cy = 0.27015;
	if (argc == 4)
	{
		vars.julia_cx = ft_atof(argv[2]);
		vars.julia_cy = ft_atof(argv[3]);
	}
	return (vars);
}
