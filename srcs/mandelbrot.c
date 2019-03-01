/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/01 17:53:33 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*mandelbrot(void *param)
{
	int		n;
	t_all	*all;

	all = (t_all*)param;
	n = 0;
	all->point.y = 0;
	all->point.x = 0;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			all->c = calcul_c(all->c, all->point, *all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (calcul_module_z(all->z) < 4 && n < MAX_ITER)
			{
				all->z = calcul_z(all->z, all->c, all->tmp);
				n++;
			}
			if (n == MAX_ITER)
			{
				put_color_outside(all->point, n, all->mlx.str, all->mlx);
			}
			all->point.x += 1;// changer valeur d'incrementation en fonction du nb de threads
		}
		all->point.x = 0;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot2(void *param)
{
	int		n;
	t_all	*all;

	all = (t_all*)param;
	n = 0;
	all->point.y = 0;
	all->point.x = 1;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			all->c = calcul_c(all->c, all->point, *all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (calcul_module_z(all->z) < 4 && n < MAX_ITER)
			{
				all->z = calcul_z(all->z, all->c, all->tmp);
				n++;
			}
			if (n == MAX_ITER)
			{
				put_color_outside(all->point, n, all->mlx.str, all->mlx);
			}
			all->point.x += 2;
		}
		all->point.x = 1;
		all->point.y++;
	}
	pthread_exit(NULL);
}


//		MULTI_THREADING

/*void		*mandelbrot3(void *param)
{
	int		n;
	t_all	*all;

	all = (t_all*)param;
	n = 0;
	all->point.y = 0;
	all->point.x = 2;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			all->c = calcul_c(all->c, all->point, *all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (calcul_module_z(all->z) < 4 && n < MAX_ITER)
			{
				all->z = calcul_z(all->z, all->c, all->tmp);
				n++;
			}
			if (n == MAX_ITER)
			{
			//	printf("b\n");
				put_color_outside(all->point, n, all->mlx.str, all->mlx);
			}
			all->point.x += 4;
		}
		all->point.x = 2;
		all->point.y++;
	}
	pthread_exit(NULL);
}

void		*mandelbrot4(void *param)
{
	int		n;
	t_all	*all;

	all = (t_all*)param;
	n = 0;
	all->point.y = 0;
	all->point.x = 1;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			all->c = calcul_c(all->c, all->point, *all->p);
			all->z.x = 0;
			all->z.y = 0;
			n = 0;
			while (calcul_module_z(all->z) < 4 && n < MAX_ITER)
			{
				all->z = calcul_z(all->z, all->c, all->tmp);
				n++;
			}
			if (n == MAX_ITER)
			{
			//	printf("b\n");
				put_color_outside(all->point, n, all->mlx.str, all->mlx);
			}
			all->point.x += 4;
		}
		all->point.x = 3;
		all->point.y++;
	}
	pthread_exit(NULL);
}*/
