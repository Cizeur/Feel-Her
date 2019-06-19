/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:46:47 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:53:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include <mlx.h>

void			ft_image_background(t_master *mstr)
{
	int i;
	int j;

	i = -1;
	while (++i < mstr->xres)
	{
		j = -1;
		while (++j < mstr->yres)
			ft_image_draw_pixel(mstr, i, j, ft_rgb(0, 0, 0));
	}
}
