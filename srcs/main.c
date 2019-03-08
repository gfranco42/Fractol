/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 18:48:36 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	which_fractal(t_all all, int plan)
{
	if (plan == 1)
		mandelbrot(all);
	else if (plan == 2)
		julia(all);
	else if (plan == 3)
		brain(all);
}

void		fail(int i)
{
	if (i == 1)
	{
		write(1, "FAIL TO CREATE THREAD\n", 22);
		exit(0);
	}
	else if (i == 2)
	{
		write(1, "FAIL TO JOIN THREAD\n", 20);
		exit(0);
	}
}

void	init_v(t_all *all)
{
	t_pos			p;
	t_pos			d;
	int				plan;

	all->point.x = 0;
	all->point.y = 0;
	all->p = &p;
	all->d = &d;
	all->plan = &plan;
	all->zoom = 1;
	all->mouse.x = 0.4;
	all->mouse.y = 0.4;
	all->color = WHITE;
	all->k = 'y';
	all->c.x = 0.3;
	all->c.y = 0.3;
}

int		main(int ac, char **av)
{
	t_all			all;

	if (ac != 2)
	{
		write(1, "usage:\n./fractol  Mandelbrot\n\t   Julia\n\t   Brain\n",
		 50);
		exit(0);
	}
	init_v(&all);
	parsing(av[1], &all);
	system("afplay ./srcs/BOHEMIAN_R &");
	mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, key, &all);
	mlx_hook(all.mlx.win, 6, 0, mouse_julia, &all);
	mlx_mouse_hook(all.mlx.win, mouse, &all);
	mlx_put_image_to_window(all.mlx.ptr, all.mlx.win, all.mlx.img, 0, 0);
	mlx_loop(all.mlx.ptr);
	return (0);
}
