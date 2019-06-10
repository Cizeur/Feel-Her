/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:47:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 09:58:27 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_mouse(t_master *mstr)
{
	t_mouse		*mouse;

	mouse = &mstr->mouse;
	mouse->btn_pressed = 0;
	mouse->prevxy[0] = 0;
	mouse->prevxy[1] = 0;
	mouse->xy[0] = 0;
	mouse->xy[1] = 0;
}

void			ft_init_mstr(t_master *mstr)
{
	int i;
	int j;

	i = -1;
	while ((j = -1) && ++i < XRES)
	{
		while (++j < YRES)
		{
			mstr->map[j][i][0] = 0;
			mstr->map[j][i][1] = 0;
		}
	}
	ft_init_mouse(mstr);
	mstr->size[0] = -1;
	mstr->size[1] = -1;
	mstr->read_lines = 0;
	mstr->turn = 0;
	mstr->player_1 = NULL;
	mstr->player_2 = NULL;
	mstr->mult = 0;
	mstr->updated = 2;
}
