/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:27:21 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 16:43:08 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	my_mlx_pixel_put(t_image *image, t_point pos, int color)
{
	int	offset;

	offset = (pos.y * image->line_length) + (pos.x * (image->bits_per_pixel
				/ 8));
	*(unsigned int *)(image->addr + offset) = color;
}
