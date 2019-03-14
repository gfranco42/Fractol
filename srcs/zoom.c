/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:02:41 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/13 14:36:55 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_on_mouse(int x, int y, t_all *all)
{
	t_cplx	f;
	t_pos	new;

	f.x = (all->p->x2 - all->p->x1) * x / WIDTH + all->p->x1;
	all->d->x1 = f.x - all->p->x1;
	all->d->x2 = all->d->x1 * all->zoom;
	new.x1 = f.x - all->d->x2;
	new.x2 = new.x1 + (all->p->x2 - all->p->x1) * all->zoom;
	all->p->x1 = new.x1;
	all->p->x2 = new.x2;
	f.y = (all->p->y2 - all->p->y1) * (HEIGHT - y) / HEIGHT + all->p->y1;
	all->d->y1 = f.y - all->p->y1;
	all->d->y2 = all->d->y1 * all->zoom;
	new.y1 = f.y - all->d->y2;
	new.y2 = new.y1 + (all->p->y2 - all->p->y1) * all->zoom;
	all->p->y1 = new.y1;
	all->p->y2 = new.y2;
}
