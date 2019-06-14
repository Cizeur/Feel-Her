/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_draw_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:35:28 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 11:35:31 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_image_draw_pixel(t_master *mstr, int x, int y, int color)
{
	char	*img_cont;

	img_cont = (mstr->mem_ptr)[I_ADR];
	if (x < mstr->xres && y < mstr->yres && x >= 0 && y >= 0)
	{
		img_cont[4 * (x + y * mstr->xres) + 0] = color % 256;
		img_cont[4 * (x + y * mstr->xres) + 1] = (color / 256) % 256;
		img_cont[4 * (x + y * mstr->xres) + 2] = color / (256 * 256);
	}
}
