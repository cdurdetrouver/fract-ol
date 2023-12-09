/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:46:06 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:08:54 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	minimandel(int x, int y, t_fractal *mandel)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	mandel->c.x = (x + mandel->xarrow) / mandel->zoom * (0.47 + 2.0)
		/ (mandel->width - 1) - 2.0;
	mandel->c.y = (y + mandel->yarrow) / mandel->zoom * (1.12 + 1.12)
		/ (mandel->width - 1) - 1.12;
	z0 = mandel->c.x;
	z1 = mandel->c.y;
	while (i++ < mandel->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + mandel->c.x;
		z1 = 2.0 * z0 * z1 + mandel->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(mandel, (int)x, (int)y, (mandel->color * i));
			break ;
		}
	}
}

void	*mandelbrotset(t_fractal *mandel)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= mandel->width)
	{
		y = -1;
		while (++y <= mandel->height)
		{
			minimandel(x, y, mandel);
		}
	}
}