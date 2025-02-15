/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:15:52 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:15:57 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && (argc != 4 || ft_strncmp(argv[1], "julia", 6)))
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
