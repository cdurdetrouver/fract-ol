/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:35:27 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 01:35:33 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	mappoint(t_fractal *fractal, double x, double y)
{
	t_complex c;
	double l;

	if (fractal->width < fractal->height)
		l = fractal->height * fractal->zoom;
	else
		l = fractal->width * fractal->zoom;
	x += fractal->xarrow;
	y += fractal->yarrow;
	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
	return (c);
}
