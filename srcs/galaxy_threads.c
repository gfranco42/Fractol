/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:21:13 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 15:27:03 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/*
void		*galaxy_th1(void *param)
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
			all->point.x += 4;
		}
		all->point.x = 2;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*galaxy_th4(void *param)
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
				all->z = calcul_z_galaxy(all->z, all->c, all->tmp);
			if (n != MAX_ITER)
				put_color_outside(all->point, n, (unsigned int*)all->mlx.str);
			all->point.x += 4;
		}
		all->point.x = 3;
		all->point.y++;
	}
	pthread_exit(NULL);
}*/
