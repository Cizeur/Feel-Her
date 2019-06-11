/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:46:47 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 10:13:27 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_image_background(t_master *mstr)
{
	int i;
	int j;

	i = -1;
	while (++i < mstr->xres)
	{
		j = -1;
		while (++j < mstr->yres)
			ft_draw_pixel(mstr, i, j, ft_rgb(0, 0, 0));
	}
}
