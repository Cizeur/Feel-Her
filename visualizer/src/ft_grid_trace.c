/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:18:09 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/10 16:18:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_grid_trace(t_master *mstr, int *size)
{
	int		i;
	int		pos[2];

	i = -1;
	while (++i <= size[0])
	{
		pos[0] = mstr->top_corner[0] + i * mstr->mult_y;
		pos[1] = mstr->top_corner[1];
		ft_line_trace(mstr, pos, mstr->mult_x * size[1] , HORI);
	}
	i = -1;
	while (++i <= size[1])
	{
		pos[0] = mstr->top_corner[0];
		pos[1] = mstr->top_corner[1] + i * mstr->mult_x;
		ft_line_trace(mstr, pos, mstr->mult_y * size[0] , VERT);
	}
}
