/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:53:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/10 14:18:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_pixel(t_master *mstr, int x, int y, int color)
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
