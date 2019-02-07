/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:49:04 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cplx			calcul_z(t_cplx z, t_cplx c, t_cplx tmp)
{
	tmp.x =  z.x * z.x - z.y * z.y;
	tmp.y = 2 * z.x * z.y;
	z.x = tmp.x;
	z.y = tmp.y;
	z.x = z.x + c.x;
	z.y = z.y + c.y;
	return (z);
}

t_cplx	calcul_c(t_cplx c, t_point point, t_pos p, t_cplx event_z)
{
	c.x = p.x1 + point.x * (p.x2 - p.x1) / (WIDTH - 1) + event_z.x;
	c.y = p.y1 + point.y * (p.y2 - p.y1) / (HEIGHT - 1) + event_z.y;
	c.y = p.y2 - c.y + p.y1;
	return (c);
}

double		calcul_module_z(t_cplx z)
{
	int		module;
	int		x;
	int		y;

	x = z.x * z.x;
	y = z.y * z.y;
	module = x + y;
	return (module);
}
