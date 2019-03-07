/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 18:09:07 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parsing(char *str, t_all all)
{
	if ((ft_strcmp("Julia", str) == 0) || (ft_strcmp("julia", str) == 0))
		julia(all);
	else if ((ft_strcmp("Mandelbrot", str) == 0) || (ft_strcmp("mandelbrot",
	 str) == 0))
		mandelbrot(all);
	else if ((ft_strcmp("Galaxy", str) == 0) || (ft_strcmp("galaxy", str) == 0))
		galaxy(all);
	else
	{
		write(1, "usage:\n./fractol  Mandelbrot\n\t   Julia\n\t   Galaxy\n",
		 50);
		exit(0);
	}
}
