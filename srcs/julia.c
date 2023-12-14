/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:53:11 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/14 19:05:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	julia_pixel(t_point pos, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = (fractal->min.x + pos.x * (fractal->max.x - fractal->min.x) / WIDTH);
	z.i = (fractal->max.y + pos.y * (fractal->min.y - fractal->max.y) / HEIGHT);
	c.r = fractal->c.r;
	c.i = fractal->c.i;
	while (i++ < fractal->iterations)
	{
		z = sum(square_complex(z), c);
		if (z.r * z.r + z.i * z.i > fractal->escapevalue)
		{
			my_mlx_pixel_put(&fractal->image, pos, fractal->color * i);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->image, pos, 0x000000);
}

void	juliaset(t_fractal *fractal)
{
	t_point	pos;

	pos.x = -1;
	while (++pos.x <= WIDTH)
	{
		pos.y = -1;
		while (++pos.y <= HEIGHT)
			julia_pixel(pos, fractal);
	}
}
