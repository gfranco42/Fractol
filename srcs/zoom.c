/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:02:41 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/20 16:19:36 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_on_mouse(int x, int y, t_all *all)
{
	t_cplx	f;
//	t_cplx	ratio_win;
//	t_cplx	ratio;
//	t_pos	data;
	t_pos	new;

/*	ratio_win.x = (all->new->x2 - all->new->x1) / (all->p->x2 - all->p->x1);
	ratio_win.y = (all->new->y2 - all->new->y1) / (all->p->y2 - all->p->y1);*/
//	ratio.x = (all->new->x2 - all->new->x1) / (all->p->x2 - all->p->x1);
//	ratio.y = (all->new->y2 - all->new->y1) / (all->p->y2 - all->p->y1);
//	printf("rx: %f, ry: %f\n", ratio_win.x, ratio_win.y);*/

//	f.x *= ratio_win.x;
//	f.y *= ratio_win.y;
	//data.x1 = all->p->x1;// * ratio.x1;
	//data.x2 = all->p->x2;// * ratio.x1;

	f.x = (all->p->x2 - all->p->x1) * x / WIDTH + all->p->x1;
	all->d->x1 = f.x - all->p->x1;
	all->d->x2 = all->d->x1 * all->zoom;
	new.x1 = f.x - all->d->x2;
	new.x2 = new.x1 + (all->p->x2 - all->p->x1) * all->zoom;
	all->p->x1 = new.x1;
	all->p->x2 = new.x2;

	/*data.y1 = all->p->y1;// * ratio.x1;
	data.y2 = all->p->y2;// * ratio.x1;*/

	f.y = (all->p->y2 - all->p->y1) * (HEIGHT - y) / HEIGHT + all->p->y1;
	all->d->y1 = f.y - all->p->y1;
	all->d->y2 = all->d->y1 * all->zoom;
	new.y1 = f.y - all->d->y2;
	new.y2 = new.y1 + (all->p->y2 - all->p->y1) * all->zoom;
	all->p->y1 = new.y1;
	all->p->y2 = new.y2;
//aprintf("x1: %f, y1: %f, x2: %f, y2: %f\n", new.x1, new.y1, new.x2, new.y2);
//	printf("x1: %f, y1: %f, x2: %f, y2: %f\n", new.x1, new.y1, new.x2, new.y2);

//(x2 - x1) * x / W + x1;

}
