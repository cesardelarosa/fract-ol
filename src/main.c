/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:15:52 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 19:53:47 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = read_args(argc, argv);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, CLOSE_WIN, 0, close_window, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	draw(&vars);
	ft_printf("\n\tControls:\n\n"
		"\tESC KEY\t\t->\texit\n"
		"\tC KEY\t\t->\tchange color\n"
		"\tR KEY\t\t->\treset position\n"
		"\tARROWS\t\t->\tmove\n"
		"\tMOUSE WHEEL\t->\tzoom\n"
		"\tLEFT CLICK\t->\tmandelbrot to julia / julia to mandelbrot\n");
	mlx_loop(vars.mlx);
	return (0);
}
