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
void	ft_write_title(t_master *mstr)
{
int pos[2];
int step;

step = 10;
pos[0] = mstr->xres / 2 - 220;
pos[1] = 0;
ft_text_draw(mstr, pos, 0,"####### ### #       #       ####### ######  ");
pos[1] += step;
ft_text_draw(mstr, pos, 0,"#        #  #       #       #       #     # ");
pos[1] += step;
ft_text_draw(mstr, pos, 0,"#        #  #       #       #       #     # ");
pos[1] += step;
ft_text_draw(mstr, pos, 0,"#####    #  #       #       #####   ###### ");
pos[1] += step;
ft_text_draw(mstr, pos, 0,"#        #  #       #       #       #   #   ");
pos[1] += step;
ft_text_draw(mstr, pos, 0,"#        #  #       #       #       #    #  ");
pos[1] += step;
ft_text_draw(mstr, pos, 0 ,"#       ### ####### ####### ####### #     # ");
                                                          
}
void	ft_write_player_name(t_master *mstr)
{
	int pos[2];

	pos[0] = 15;
	pos[1] = 15;
	ft_text_draw(mstr, pos, ft_color_gradient(0, 0, mstr->color_1_tg, 1),
		mstr->player_1 ? mstr->player_1 : "NO PLAYER");
	pos[0] = -15 + mstr->xres - 
	ft_strlen(mstr->player_2? mstr->player_2 : "NO PLAYER") * LARGEUR_CHAR;
	ft_text_draw(mstr, pos, ft_color_gradient(0, 0, mstr->color_2_tg, 1),
		mstr->player_2? mstr->player_2 : "NO PLAYER");
}

void		ft_top_bar(t_master *mstr)
{
	int i;
	int pos[3];

	i = -1;
	while (++i < TOP_ROW_THICKNESS)
	{
		pos[1] = 0;
		pos[0] = i;
		pos[2] = 0xFFFFFF;
		ft_line_trace(mstr, pos, mstr->xres, HORI);
	}

}

void	ft_refresh(t_master *mstr)
{
		sub_parser_stockage(mstr);
		ft_grid_size(mstr, mstr->size);
		ft_grid_trace(mstr, mstr->size);
		ft_grid_fill(mstr, mstr->size);
		ft_top_bar(mstr);
		ft_image_dump(mstr->mem_ptr);
		ft_image_background(mstr);
		ft_write_player_name(mstr);
		ft_write_title(mstr);
		mstr->updated = mstr->updated == 1 ? 0 : mstr->updated;
}
