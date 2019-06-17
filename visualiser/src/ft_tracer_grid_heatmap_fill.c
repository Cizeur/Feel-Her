/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer_grid_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:16:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 19:02:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static void		ft_tracer_heat_cell_fill(t_master *mstr, int i, int j)
{
	int jj;
	int pos[3];
	int h_amp;

	h_amp = mstr->size[0] + mstr->size[1];
	jj = -1;
	while (++jj <= mstr->mult_y)
	{
		pos[2] = ft_color_gradient(h_amp - ft_abs(mstr->map[j][i][1]),
				h_amp, mstr->heatmap_c_tg, 1);
		pos[0] = mstr->top_corner[0] + j * mstr->mult_y + jj;
		pos[1] = mstr->top_corner[1] + i * mstr->mult_x;
		ft_image_line_trace(mstr, pos, mstr->mult_x, HORI);
	}
}

void			ft_tracer_grid_heatmap_fill(t_master *mstr, int *size)
{
	int		i;
	int		j;

	j = -1;
	if (!mstr->heatmap_tg)
		return ;
	while ((i = -1) && ++j < size[0])
	{
		while (++i < size[1])
		{
			if (mstr->map[j][i][1] < 0)
				ft_tracer_heat_cell_fill(mstr, i, j);
		}
	}
}
