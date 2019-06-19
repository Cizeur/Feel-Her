/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_top_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:02:33 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:42:18 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static void				ft_topbar_title(t_master *mstr)
{
	int		pos[2];
	int		step;
	void	(*ft_wr)();

	step = 10;
	ft_wr = ft_window_text_draw;
	pos[0] = (mstr->xres - LARGEUR_CHAR * 45) / 2;
	pos[1] = 0;
	ft_wr(mstr, pos, 0, "####### ### #       #       ####### ######  ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#        #  #       #       #       #     # ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#        #  #       #       #       #     # ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#####    #  #       #       #####   ######  ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#        #  #       #       #       #   #   ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#        #  #       #       #       #    #  ");
	pos[1] += step;
	ft_wr(mstr, pos, 0, "#       ### ####### ####### ####### #     # ");
}

static void				ft_topbar_player_name(t_master *mstr)
{
	int pos[2];

	pos[0] = 15;
	pos[1] = 15;
	ft_window_text_draw(mstr, pos, ft_color_gradient(0, 0, mstr->color_1_tg, 0),
			mstr->player_1 ? mstr->player_1 : "NO PLAYER");
	pos[0] = -15 + mstr->xres -
		ft_strlen(mstr->player_2 ? mstr->player_2 : "NO PLAYER") * LARGEUR_CHAR;
	ft_window_text_draw(mstr, pos, ft_color_gradient(0, 0, mstr->color_2_tg, 0),
			mstr->player_2 ? mstr->player_2 : "NO PLAYER");
}

static void				ft_topbar_score(t_master *mstr)
{
	int		i[2];
	int		score;
	int		pos[2];
	int		ten_pow;
	char	score_str[10];

	i[0] = -1;
	pos[1] = 30 + LARGEUR_CHAR;
	while (++i[0] < 2)
	{
		ft_bzero(score_str, 10);
		ten_pow = 100000000;
		score = !i[0] ? mstr->score_1 : mstr->score_2;
		pos[0] = !i[0] ? 15 : mstr->xres - 15 - LARGEUR_CHAR * 9;
		i[1] = 10;
		while (--i[1])
		{
			score_str[9 - i[1]] = score / ten_pow + '0';
			score %= ten_pow;
			ten_pow /= 10;
		}
		ft_window_text_draw(mstr, pos, ft_color_gradient(0, 0,
				!i[0] ? mstr->color_1_tg : mstr->color_2_tg, 0),
				score_str);
	}
}

void					ft_window_text_top_bar(t_master *mstr)
{
	ft_topbar_player_name(mstr);
	ft_topbar_score(mstr);
	ft_topbar_title(mstr);
}
