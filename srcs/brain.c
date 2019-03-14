/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:45:52 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/13 13:26:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*brain_th1(void *param)
{
	t_all	*all;

	all = (t_all*)param;
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
			calcul_brain(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*brain_th2(void *param)
{
	t_all	*all;

	all = (t_all*)param;
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
			calcul_brain(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*brain_th3(void *param)
{
	t_all	*all;

	all = (t_all*)param;
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
			calcul_brain(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*brain_th4(void *param)
{
	t_all	*all;

	all = (t_all*)param;
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
			calcul_brain(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		brain(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		all_th[i] = all;
		all_th[i].c.x = 0.330625;
		all_th[i].c.y = -0.035852;
	}
	if (all.zoom == 1)
		set_plan(all.p, 3);
	if ((pthread_create(&th[0], NULL, brain_th1, &all_th[0])))
		fail(1);
	if ((pthread_create(&th[1], NULL, brain_th2, &all_th[1])))
		fail(1);
	if ((pthread_create(&th[2], NULL, brain_th3, &all_th[2])))
		fail(1);
	if ((pthread_create(&th[3], NULL, brain_th4, &all_th[3])))
		fail(1);
	while (--i > -1)
		if ((pthread_join(th[i], NULL)))
			fail(2);
}
