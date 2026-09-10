/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:15:52 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 16:33:54 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = parser(argc, argv);
	mlx_key_hook(vars.win, (int (*)())(void *)key_hook, &vars);
    mlx_hook(vars.win, CLOSE_WIN, 0, (int (*)())(void *)close_window, &vars);
    mlx_mouse_hook(vars.win, (int (*)())(void *)mouse_hook, &vars);
	draw(&vars);
	ft_printf("\n\tControls:\n\n"
		"\tESC KEY\t\t->\texit\n"
		"\tMOUSE WHEEL\t->\tzoom\n");
	mlx_loop(vars.mlx);
	cleanup(&vars);
	return (0);
}
