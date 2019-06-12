/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_simple_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:46:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 10:22:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_key_simple_press(int key, t_master *mstr)
{
	close(0);
	key != ESCAPE ? key = key + 0 : ft_exit(STANDARD_EXIT, mstr);
		printf("key - %d\n", key);
	if (key == TILDE && (mstr->updated = ft_max(mstr->updated, 1)))
		mstr->square_tg = (mstr->square_tg + 1) % 2;
	if (key == TOUCH_1 && (mstr->updated = ft_max(mstr->updated, 1)))
		mstr->color_1_tg = (mstr->color_1_tg + 1) % 8;
	if (key == TOUCH_2 && (mstr->updated = ft_max(mstr->updated, 1)))
		mstr->color_2_tg = (mstr->color_2_tg + 1) % 8;
	if (key == TOUCH_Q && (mstr->updated = ft_max(mstr->updated, 1)))
		mstr->color_1_g_tg = (mstr->color_1_g_tg + 1) % 2;
	if (key == TOUCH_W && (mstr->updated = ft_max(mstr->updated, 1)))
		mstr->color_2_g_tg = (mstr->color_2_g_tg + 1) % 2;
	if (key == TOUCH_P)
		mstr->updated = 3;
	return (key);

}
