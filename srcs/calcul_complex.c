/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/06 16:37:39 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_z			calcul_z(t_z z, t_c c)
{
//	printf("z.x: %f, z.y: %f, c.x: %f, c.y: %f\n", z.x, z.y, c.x, c.y);
	z.x = (z.x * z.x) + c.x;
	z.y = (z.y * z.y) + c.y;
	return (z);
}

t_c			calcul_c(t_c c, int x, int y)
{
	(void)x;
	(void)y;
	c.x = WIDTH / 2 / WIDTH;
	c.y = HEIGHT / 2 / HEIGHT;
//	printf("x: %d, y: %d, c.x: %f, c.y: %f\n", x, y, c.x, c.y);
	return (c);
}

double		calcul_module_z(t_z z)
{
	int		module;
	int		x;
	int		y;

//	printf("x: %f |y: %f", z.x, z.y);
	x = z.x * z.x;
	y = z.y * z.y;
	module = x + y;
	return (module);
}
