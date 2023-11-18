/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:32:44 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/18 10:58:28 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define CLOSE_WIN 17

int	close_window_hook(t_params *params);
int	key_hook(int keycode, t_params *params);
int	mouse_hook(int button, int x, int y, t_params *params);

#endif
