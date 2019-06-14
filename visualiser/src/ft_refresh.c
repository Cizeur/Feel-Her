/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:23:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/15 18:29:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void	ft_refresh(t_master *mstr)
{
		sub_parser_stockage(mstr);
		ft_tracer(mstr);
		ft_image_top_bar_bg(mstr);
		ft_image_dump(mstr->mem_ptr);
		ft_image_background(mstr);
		ft_window_text_top_bar(mstr);
		mstr->updated = mstr->updated == U_THE_MAP ? U_IDLE : mstr->updated;
}
