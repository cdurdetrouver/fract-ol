/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:30:32 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:33:49 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	mouse_scroll(int button, int x, int y, void *param)
{
	(void)param;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int	key_press(int keycode, void *param)
{
	(void)param;
	(void)keycode;
	return (0);
}

int	key_release(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		close_window(param);
	return (0);
}
