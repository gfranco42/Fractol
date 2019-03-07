/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 15:22:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*julia_th1(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 0;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_first_z_galaxy(&all->point, &all->z, all->p);
			n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
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

void		*julia_th2(void *param)
{
	t_all	*all;
	int		n;

	all = (t_all*)param;
	all->point.x = 1;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_first_z_galaxy(&all->point, &all->z, all->p);
			n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
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

void		*julia_th3(void *param)
{
	t_all	*all;
	int			n;

	all = (t_all*)param;
	all->point.x = 2;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_first_z_galaxy(&all->point, &all->z, all->p);
			n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
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

void		*julia_th4(void *param)
{
	t_all	*all;
	int			n;

	all = (t_all*)param;
	all->point.x = 3;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			calcul_first_z_galaxy(&all->point, &all->z, all->p);
			n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
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

void		julia(t_all all)
{
	pthread_t	th[4];
	t_all		all_th[4];
	int			i;

	i = -1;
	while (++i < 4)
		all_th[i] = all;
	if (*all.plan != 2)
		set_plan(all.p, 2);
	*all.plan = 2;
	while (--i > -1)
	{
		all_th[i].c.x = all.yolo1;
		all_th[i].c.y = all.yolo2;
	}
	if ((pthread_create(&th[0], NULL, julia_th1, &all_th[0])))
		fail(1);
	if ((pthread_create(&th[1], NULL, julia_th2, &all_th[1])))
		fail(1);
	if ((pthread_create(&th[2], NULL, julia_th3, &all_th[2])))
		fail(1);
	if ((pthread_create(&th[3], NULL, julia_th4, &all_th[3])))
		fail(1);
	while (++i < 4)
	if ((pthread_join(th[i], NULL)))
		fail(2);
}
