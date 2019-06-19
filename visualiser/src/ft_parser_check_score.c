/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_score.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:11:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:36:27 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include "libft/libft.h"

void			ft_parser_check_score(t_master *mstr, int *size)
{
	int i;
	int j;
	int check[2];

	j = -1;
	ft_bzero(check, sizeof(check));
	while ((i = -1) && ++j < size[0])
	{
		while (++i < size[1])
		{
			check[0] = mstr->map[j][i][0] == 1 ? 1 : check[0];
			check[1] = mstr->map[j][i][0] == -1 ? 1 : check[1];
		}
	}
	mstr->score_1 += check[0] ? 1 : 0;
	mstr->score_2 += check[1] ? 1 : 0;
	if (mstr->score_1 > mstr->score_2 + 1 || mstr->score_2 > mstr->score_1)
		mstr->updated = mstr->updated == 4 ? 2 : mstr->updated;
}
