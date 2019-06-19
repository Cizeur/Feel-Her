/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:17:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:44:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_tracer_grid(t_master *mstr, int *size)
{
	int		i;
	int		pos[3];

	i = -1;
	pos[2] = ft_rgb(255, 255, 255);
	while (++i <= size[0])
	{
		pos[0] = mstr->top_corner[0] + i * mstr->mult_y;
		pos[1] = mstr->top_corner[1];
		ft_image_line_trace(mstr, pos, mstr->mult_x * size[1], HORI);
	}
	i = -1;
	while (++i <= size[1])
	{
		pos[0] = mstr->top_corner[0];
		pos[1] = mstr->top_corner[1] + i * mstr->mult_x;
		ft_image_line_trace(mstr, pos, mstr->mult_y * size[0], VERT);
	}
}
