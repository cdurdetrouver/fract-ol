/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:25:48 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/14 19:21:10 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	get_color(int i, int iterations)
{
	int		color;
	double	t;

	t = (double)i / (double)iterations;
	color = 0;
	color += (int)(9 * (1 - t) * pow(t, 3) * 255) << 16;
	color += (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 8;
	color += (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
