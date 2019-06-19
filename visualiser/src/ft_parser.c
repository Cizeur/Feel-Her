/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:36:47 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:36:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void			ft_parser(t_master *mstr)
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
	if (mstr->heatmap_tg && mstr->updated >= U_THE_MAP)
		ft_parser_heatmap(mstr);
}
