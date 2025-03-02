/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:28 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:04:30 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = parser(argc, argv);
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
	cleanup(&vars);
	return (0);
}
