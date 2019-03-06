/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/06 18:45:37 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		calcul_first_z_galaxy(t_point *point, t_cplx *z, t_pos *p)
{
	 z->x = p->x1 + point->x * (p->x2 - p->x1) / WIDTH;
	 z->y = p->y1 + point->y * (p->y2 - p->y1) / HEIGHT;
	 z->y = p->y2 - z->y + p->y1;
}

void		galaxy(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int			i;

	i = -1;
	while (++i < 4)
		all_th[i] = all;
	if (*all.plan != 3)
		set_plan(all.p, 3);
	*all.plan = 3;
	while (--i > -1)
	{
		all_th[i].c.x = 0.5898;
		all_th[i].c.y = 1.1957;
	}
	if ((pthread_create(&th[0], NULL, galaxy_th1, &all_th[0])))
		fail(1);
	if ((pthread_create(&th[1], NULL, galaxy_th2, &all_th[1])))
		fail(1);
	if ((pthread_create(&th[2], NULL, galaxy_th3, &all_th[2])))
		fail(1);
	if ((pthread_create(&th[3], NULL, galaxy_th4, &all_th[3])))
		fail(1);
	while (++i < 4)
	if ((pthread_join(th[i], NULL)))
		fail(2);
}
