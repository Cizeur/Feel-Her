/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:39:39 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/11 09:39:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_cell_fill(t_master *mstr, int i, int j)
{
	int jj;
	int pos[3];

	jj= -1;
	while (++jj < mstr->mult_y)
	{
		pos[2] = mstr->map[j][i][0] < 0 ? 
		ft_color_gradient(mstr->map[j][i][0] - mstr->amp_x[0], mstr->amp_x[2], 4, 1):
		ft_color_gradient(mstr->amp_o[0] - mstr->map[j][i][0] , mstr->amp_o[2], 1, 1);
		pos[0] = mstr->top_corner[0] + j * mstr->mult_y + jj;
		pos[1] = mstr->top_corner[1] + i * mstr->mult_x;
		ft_line_trace(mstr, pos, mstr->mult_x , HORI);
	}
}



void		ft_grid_fill(t_master *mstr, int *size)
{
	int		i;
	int		j;

	j = -1;
	while ((i = -1) && ++j <= size[0])
	{
		while (++i <= size[1])
	{
		if (mstr->map[j][i][0])
			ft_cell_fill(mstr, i, j);
	}
	}
}
