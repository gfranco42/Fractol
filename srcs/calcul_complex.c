/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/14 16:02:02 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			calcul_brain(t_all all, unsigned int *str)
{
	int		n;
	double	tmp;

	n = 1;
	while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n++ < MAX_ITER)
	{
		tmp = all.z.x;
		all.z.x = all.z.x * all.z.x - all.z.y * all.z.y + all.c.x;
		all.z.y = 2 * tmp * all.z.y + all.c.y;
		all.z.x = fabs(all.z.x);
		all.z.y = -fabs(all.z.y);
	}
	if (n != MAX_ITER)
		str[all.point.y * WIDTH + all.point.x] = all.color * n;
}

void			calcul_julia(t_all all, unsigned int *str)
{
	int		n;
	double	tmp;

	n = 1;
	while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n++ < MAX_ITER)
	{
		tmp = all.z.x;
		all.z.x = all.z.x * all.z.x - all.z.y * all.z.y + all.c.x;
		all.z.y = 2 * tmp * all.z.y + all.c.y;
	}
	if (n != MAX_ITER)
		str[all.point.y * WIDTH + all.point.x] = all.color * n;
}

void			calcul_mandelbrot(t_all all, unsigned int *str)
{
	int		n;
	double	tmp;

	n = 1;
	while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n++ < MAX_ITER)
	{
		tmp = all.z.x;
		all.z.x = all.z.x * all.z.x - all.z.y * all.z.y + all.c.x;
		all.z.y = 2 * tmp * all.z.y + all.c.y;
	}
	if (n != MAX_ITER)
		str[all.point.y * WIDTH + all.point.x] = all.color * n;
}
