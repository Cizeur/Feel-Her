/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_line_trace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:35:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:36:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_image_line_trace(t_master *mstr, int pos[3], int len,
				int orientation)
{
	int i;

	i = -1;
	while (++i <= len)
		ft_image_draw_pixel(mstr, orientation == HORI ? pos[1] + i : pos[1],
		orientation == VERT ? pos[0] + i : pos[0], pos[2]);
}
