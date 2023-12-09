/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:35:39 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:13:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	get_fractal(char *arg)
{
	if (ft_strncmp(arg, "Mandelbrot", 10) == 0)
		return (1);
	// else if (ft_strncmp(arg, "Julia", 5) == 0)
	// 	return (2);
	// else if (ft_strncmp(arg, "Burning Ship", 12) == 0)
	// 	return (3);
	// else if (ft_strncmp(arg, "Tricorn", 7) == 0)
	// 	return (4);
	return (0);
}

static int	ft_read(void)
{
	char	buffer[13];
	int		i;
	int		c;

	i = 0;
	while ((read(STDIN_FILENO, &c, 1) > 0))
	{
		if (c == '\n')
			break ;
		buffer[i++] = (char)c;
	}
	buffer[i] = '\0';
	return (get_fractal(buffer));
}

char	*print_fractal(int choice)
{
	if (choice == 1)
		return ("Mandelbrot");
	// else if (choice == 2)
	// 	return ("Julia");
	// else if (choice == 3)
	// 	return ("Burning Ship");
	// else if (choice == 4)
	// 	return ("Tricorn");
	return ("");
}

int	menu(void)
{
	int	choice;

	ft_printf("Choisissez une fractale :\n");
	ft_printf("- Mandelbrot\n");
	// ft_printf("- Julia\n");
	// ft_printf("- Burning Ship\n");
	// ft_printf("- Tricorn\n");
	ft_printf("\nEntrez le nom de votre choix : ");
	choice = ft_read();
	while (choice == 0)
	{
		ft_printf("Choix non valide.\n");
		ft_printf("Entrez votre choix : ");
		choice = ft_read();
	}
	return (choice);
}
