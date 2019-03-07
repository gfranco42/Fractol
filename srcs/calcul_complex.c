/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 19:13:48 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			calcul_galaxy(t_all all)
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
	{
		all.mlx.str[(all.point.y * WIDTH + all.point.x) * 4] = 0x01;
		all.mlx.str[(all.point.y * WIDTH + all.point.x) * 4 + 1] = 0xDF;
		all.mlx.str[(all.point.y * WIDTH + all.point.x) * 4 + 2] = 0x3A / n;
	}
}

void			calcul_z(t_cplx *z, t_cplx *c, t_cplx *tmp)
{
	tmp->x = z->x;
	z->x = z->x * z->x - z->y * z->y + c->x;
	z->y = 2 * tmp->x * z->y + c->y;
}

void		calcul_first_z_galaxy(t_point *point, t_cplx *z, t_pos *p)
{
	 z->x = p->x1 + point->x * (p->x2 - p->x1) / WIDTH;
	 z->y = p->y1 + point->y * (p->y2 - p->y1) / HEIGHT;
	 z->y = p->y2 - z->y + p->y1;
}

t_cplx			calcul_z_galaxy(t_cplx z, t_cplx c, t_cplx tmp)
{
	tmp.x = z.x;
	z.x = z.x * z.x - z.y * z.y + c.x;
	z.y = 2 * tmp.x * z.y + c.y;
	z.x = fabs(z.x);
	z.y = -fabs(z.y);
	return (z);
}

void			calcul_c(t_cplx *c, t_point *point, t_pos *p)
{
	c->x = p->x1 + point->x * (p->x2 - p->x1) / WIDTH;
	c->y = p->y1 + point->y * (p->y2 - p->y1) / HEIGHT;
	c->y = p->y2 - c->y + p->y1;
}

double			calcul_module_z(t_cplx z)
{
	int		module;
	int		x;
	int		y;

	x = z.x * z.x;
	y = z.y * z.y;
	module = x + y;
	return (module);
}

