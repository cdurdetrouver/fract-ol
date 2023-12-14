/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:34:22 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/10 20:15:46 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx.mlx_ptr, fractal->image.img);
	mlx_destroy_window(fractal->mlx.mlx_ptr, fractal->mlx.win);
	mlx_destroy_display(fractal->mlx.mlx_ptr);
	free(fractal->mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}

int	close_window(void *param)
{
	ft_printf("\nBye!");
	exit(freeall(param));
	return (EXIT_SUCCESS);
}
