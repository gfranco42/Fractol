/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/14 16:10:22 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*mandelbrot_th1(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 0;
		while (all->point.x < WIDTH)
		{
			all->c.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->c.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->c.y = all->p->y2 - all->c.y + all->p->y1;
			all->z.x = 0;
			all->z.y = 0;
			calcul_mandelbrot(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th2(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 1;
		while (all->point.x < WIDTH)
		{
			all->c.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->c.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->c.y = all->p->y2 - all->c.y + all->p->y1;
			all->z.x = 0;
			all->z.y = 0;
			calcul_mandelbrot(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th3(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 2;
		while (all->point.x < WIDTH)
		{
			all->c.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->c.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->c.y = all->p->y2 - all->c.y + all->p->y1;
			all->z.x = 0;
			all->z.y = 0;
			calcul_mandelbrot(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th4(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 3;
		while (all->point.x < WIDTH)
		{
			all->c.x = all->p->x1 + all->point.x * (all->p->x2 - all->p->x1)
			/ WIDTH;
			all->c.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1)
			/ HEIGHT;
			all->c.y = all->p->y2 - all->c.y + all->p->y1;
			all->z.x = 0;
			all->z.y = 0;
			calcul_mandelbrot(*all, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		mandelbrot(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int			i;

	i = -1;
	while (++i < 4)
		all_th[i] = all;
	while (--i > -1)
	{
		all_th[i].c.x = 0;
		all_th[i].c.y = 0;
	}
	if (all.fr == 0)
		set_plan(all.p, 1);
	if ((pthread_create(&th[0], NULL, mandelbrot_th1, &all_th[0])))
		fail(1);
	if ((pthread_create(&th[1], NULL, mandelbrot_th2, &all_th[1])))
		fail(1);
	if ((pthread_create(&th[2], NULL, mandelbrot_th3, &all_th[2])))
		fail(1);
	if ((pthread_create(&th[3], NULL, mandelbrot_th4, &all_th[3])))
		fail(1);
	while (++i < 4)
		if ((pthread_join(th[i], NULL)))
			fail(2);
}
