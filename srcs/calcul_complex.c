/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/05 17:02:24 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_z			calcul_z(t_z z, t_c c)
{
	z.x = (z.x * z.x) + c.x;
	z.y = (z.y * z.y) + c.y;
	return (z);
}

t_c			calcul_c(t_c c, int x, int y)
{
	c.x = x * WIDTH / 2 - 1;
	c.y = y * HEIGHT / 2 - 1;
	return (c);
}

double		calcul_module_z(t_z z)
{
	int		module;
	int		x;
	int		y;

	x = z.x * z.x;
	y = z.y * z.y;
	module = x + y;
	return (module);
}
