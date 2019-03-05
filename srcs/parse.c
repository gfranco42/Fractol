/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/05 16:40:37 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parsing(char str, t_all all)
{
	if (ft_strcmp("Julia", str) == 0)
		julia(all);
	if (ft_strcmp("Mandelbrot", str) == 0)
		mandelbrot(all);
	if (ft_strcmp("galaxy", str) == 0)
		galaxy(all);
}
