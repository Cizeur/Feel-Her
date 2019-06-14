/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_top_bar_bg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:38:07 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 13:59:51 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_image_top_bar_bg(t_master *mstr)
{
	int pos[3];

	pos[0] = -1;
	while (++pos[0] < TOP_ROW_THICKNESS)
	{
		pos[1] = 0;
		pos[2] = 0xFFFFFF;
		ft_image_line_trace(mstr, pos, mstr->xres, HORI);
	}
}
