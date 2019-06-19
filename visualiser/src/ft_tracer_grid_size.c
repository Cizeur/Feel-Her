/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer_grid_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:17:28 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:44:32 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_tracer_grid_size(t_master *mstr, int *size)
{
	int multx;
	int multy;
	int max_x;
	int max_y;

	max_x = (mstr->xres - 1) * FILL_PERCENT / 100;
	max_y = (mstr->yres - TOP_ROW_THICKNESS - 1) * FILL_PERCENT / 100;
	multx = 0;
	multy = 0;
	while ((multx + 1) * size[1] < max_x)
		(multx)++;
	while ((multy + 1) * size[0] < max_y)
		(multy)++;
	multx = mstr->square_tg ? ft_min(multx, multy) : multx;
	multy = mstr->square_tg ? ft_min(multx, multy) : multy;
	mstr->mult_x = multx;
	mstr->mult_y = multy;
	mstr->top_corner[0] = ((mstr->yres + TOP_ROW_THICKNESS - 1)
			- size[0] * multy) / 2;
	mstr->top_corner[1] = ((mstr->xres - 1) - size[1] * multx) / 2;
}
