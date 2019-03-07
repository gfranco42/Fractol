/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 19:05:53 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*void		*galaxy_th1(void *param)
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
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
				//put_color_inside(all->point, n, (unsigned int*)*//*all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 0;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th2(void *param)
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
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
				//put_color_inside(all->point, n, unsigned int*)*//*all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 1;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th3(void *param)
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
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
				//put_color_inside(all->point, n, (unsigned int*)*//*all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 2;
		all->point.y++;
	}
	pthread_exit(NULL);
}*/
void		*galaxy_th1(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 0;
		while (all->point.x < WIDTH)
		{
	 		all->z.x =	all->p->x1 + all->point.x * (all->p->x2 - all->p->x1) / WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1) / HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			//calcul_first_z_galaxy(&all->point, &all->z, all->p);
			calcul_galaxy(*all);
			/*n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);*/
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th2(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 1;
		while (all->point.x < WIDTH)
		{
	 		all->z.x =	all->p->x1 + all->point.x * (all->p->x2 - all->p->x1) / WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1) / HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			//calcul_first_z_galaxy(&all->point, &all->z, all->p);
			calcul_galaxy(*all);
			/*n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);*/
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th3(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 2;
		while (all->point.x < WIDTH)
		{
	 		all->z.x =	all->p->x1 + all->point.x * (all->p->x2 - all->p->x1) / WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1) / HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			//calcul_first_z_galaxy(&all->point, &all->z, all->p);
			calcul_galaxy(*all);
			/*n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);*/
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th4(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->point.y = 0;
	while (all->point.y < HEIGHT)
	{
		all->point.x = 3;
		while (all->point.x < WIDTH)
		{
	 		all->z.x =	all->p->x1 + all->point.x * (all->p->x2 - all->p->x1) / WIDTH;
			all->z.y = all->p->y1 + all->point.y * (all->p->y2 - all->p->y1) / HEIGHT;
			all->z.y = all->p->y2 - all->z.y + all->p->y1;
			//calcul_first_z_galaxy(&all->point, &all->z, all->p);
			calcul_galaxy(*all);
			/*n = 1;
			while (all->z.x * all->z.x + all->z.y * all->z.y < 4 &&
			 n++ < MAX_ITER)
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);*/
			all->point.x += 4;
		}
		all->point.y++;
	}
	pthread_exit(NULL);
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
