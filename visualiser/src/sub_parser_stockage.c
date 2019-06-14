/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parser_stockage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:49:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 17:36:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void			sub_parser_stockage(t_master *mstr)
{
	if (mstr->updated >= U_ONE_TURN && mstr->still_reading)
	{
		ft_parser_output_skimmer(mstr, mstr->size);
		if (mstr->still_reading)
			ft_parser_check_score(mstr, mstr->size);
		else
		{
			mstr->color_1_g_tg = 0;
			mstr->color_2_g_tg = 0;
		}
		mstr->updated = mstr->updated == U_ONE_TURN ? U_THE_MAP : mstr->updated;
	}
}
