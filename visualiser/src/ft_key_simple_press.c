/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_simple_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:46:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:49:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static void		ft_color_toggling(int key, t_master *mstr)
{
	if (key == TOUCH_1 && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->color_1_tg = (mstr->color_1_tg + 1) % 8;
	if (key == TOUCH_2 && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->color_2_tg = (mstr->color_2_tg + 1) % 8;
	if (key == TOUCH_Q && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->color_1_g_tg = (mstr->color_1_g_tg + 1) % 2;
	if (key == TOUCH_W && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->color_2_g_tg = (mstr->color_2_g_tg + 1) % 2;
	if (key == TOUCH_H && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->heatmap_tg = (mstr->heatmap_tg + 1) % 3;
	if (key == TOUCH_3 && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->heatmap_c_tg = (mstr->heatmap_c_tg + 1) % 8;
}

static void		ft_reset_game(t_master *mstr)
{
	if (mstr->player_1)
		ft_memdel((void **)&mstr->player_1);
	if (mstr->player_2)
		ft_memdel((void **)&mstr->player_2);
	ft_init_mstr(mstr, 0);
	mstr->current = mstr->output;
	mstr->buffer_pos = (char *)mstr->current->content;
}

int				ft_key_simple_press(int key, t_master *mstr)
{
	key != ESCAPE ? key = key + 0 : ft_exit(STANDARD_EXIT, mstr);
	ft_color_toggling(key, mstr);
	if (key == TILDE && (mstr->updated = ft_max(mstr->updated, U_THE_MAP)))
		mstr->square_tg = (mstr->square_tg + 1) % 2;
	if (key == TOUCH_L)
		mstr->updated = U_TO_LOOSE;
	if (key == TOUCH_R && (mstr->updated = U_ONE_TURN))
		ft_reset_game(mstr);
	if (key == TOUCH_P)
		mstr->updated = U_TO_THE_END;
	return (key);
}
