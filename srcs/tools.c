/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:26:22 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 18:35:04 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		set_plan(t_pos *pos, int plan)
{
	if (plan == 1)
	{
		pos->x1 = -2.1;
		pos->x2 = 0.6;
		pos->y1 = -1.2;
		pos->y2 = 1.2;
	}
	else if (plan == 2)
	{
		pos->x1 = -1.1;
		pos->x2 = 1;
		pos->y1 = -1.2;
		pos->y2 = 1.2;

	}
	else if (plan == 3)
	{
		pos->x1 = -1;
		pos->x2 = 1;
		pos->y1 = -1.5;
		pos->y2 = 1.5;
	}
}

void		sound_tool(int key, char *k)
{
	if (key == 256 && *k == 'y')
	{
		*k = 'n';
		system("killall afplay &");
	}
	else if (key == 256 && *k == 'n')
	{
		*k = 'y';
		system("afplay ./srcs/BOHEMIAN_R &");
	}
}
