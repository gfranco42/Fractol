/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 16:55:30 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*mandelbrot_th1(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 0;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_c(&all->c, &all->point, all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 && n++ < MAX_ITER)
				calcul_z(&all->z, &all->c, &all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 0;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th2(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 1;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_c(&all->c, &all->point, all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 && n++ < MAX_ITER)
				calcul_z(&all->z, &all->c, &all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 1;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th3(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 2;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_c(&all->c, &all->point, all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 && n++ < MAX_ITER)
				calcul_z(&all->z, &all->c, &all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 2;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot_th4(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 3;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_c(&all->c, &all->point, all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 && n++ < MAX_ITER)
				calcul_z(&all->z, &all->c, &all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 3;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		mandelbrot(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int		i;

	i = -1;
	while (++i < 4)
		all_th[i] = all;
	if (*all.plan != 1)
		set_plan(all.p, 1);
	while (--i > -1)
	{
		all_th[i].c.x = 0;
		all_th[i].c.y = 0;
	}
	*all.plan = 1;
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
