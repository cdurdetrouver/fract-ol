/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:48:08 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:51:26 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		close_window(mlx);
	else if (keycode == UP)
		mlx->fractal->yarrow -= 10;
	else if (keycode == DOWN)
		mlx->fractal->yarrow += 10;
	else if (keycode == LEFT)
		mlx->fractal->xarrow -= 10;
	else if (keycode == RIGHT)
		mlx->fractal->xarrow += 10;
}
