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

#include "fdf.h"

void	ft_refresh(t_master *mstr)
{
		if (mstr->updated == 2)
			sub_parser_stockage(mstr);
		ft_grid_size(mstr, mstr->size);
		ft_grid_trace(mstr, mstr->size);
		ft_grid_fill(mstr, mstr->size);
		ft_image_dump(mstr->mem_ptr);
		ft_image_background(mstr);
	//	ft_text_draw(mstr, pos, 255, mstr->player_1);

}
