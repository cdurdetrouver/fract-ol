/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:35:27 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 20:12:23 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

t_complex	sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

t_complex	square_complex(t_complex a)
{
	t_complex	c;

	c.r = a.r * a.r - a.i * a.i;
	c.i = 2 * a.r * a.i;
	return (c);
}

t_complex	square_complex_abs(t_complex a)
{
	t_complex	c;

	c.r = a.r * a.r - a.i * a.i;
	c.i = 2 * fabs(a.r * a.i);
	return (c);
}
