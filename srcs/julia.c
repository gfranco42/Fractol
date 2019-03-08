/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:43:27 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 14:43:38 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*julia_th1(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->c.x = all->mouse.x;
	all->c.y = all->mouse.y;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 0;
		while (all->point.x < WIDTH)
		{
			all->z.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			calcul_julia(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*julia_th2(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->c.x = all->mouse.x;
	all->c.y = all->mouse.y;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 1;
		while (all->point.x < WIDTH)
		{
			all->z.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			calcul_julia(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*julia_th3(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->c.x = all->mouse.x;
	all->c.y = all->mouse.y;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 2;
		while (all->point.x < WIDTH)
		{
			all->z.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			calcul_julia(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*julia_th4(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->c.x = all->mouse.x;
	all->c.y = all->mouse.y;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 3;
		while (all->point.x < WIDTH)
		{
			all->z.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			calcul_julia(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		julia(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		all_th[i] = all;
		all_th[i].c.x = 0.4;
		all_th[i].c.y = 0.4;
	}
	if (*all.plan != 2)
		set_plan(all.p, 2);
	*all.plan = 2;
	if ((pthread_create(&th[0], NULL, julia_th1, &all_th[0])))
		fail(1);
	if ((pthread_create(&th[1], NULL, julia_th2, &all_th[1])))
		fail(1);
	if ((pthread_create(&th[2], NULL, julia_th3, &all_th[2])))
		fail(1);
	if ((pthread_create(&th[3], NULL, julia_th4, &all_th[3])))
		fail(1);
	while (--i > -1)
		if ((pthread_join(th[i], NULL)))
			fail(2);
}
