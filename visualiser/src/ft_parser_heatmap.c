/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_heatmap_gen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:14:41 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:39:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static int		ft_update_j(t_master *mstr, int i, int j, int sz)
{
	int ii;
	int changed;
	int value;

	changed = 0;
	ii = ft_max(0, i - sz);
	while (j - sz >= 0 && ii <= ft_min(mstr->size[1] - 1, i + sz))
	{
		value = -(sz + ft_abs(i - ii));
		if ((mstr->map[j - sz][ii][1] < value) && (changed = 1))
			mstr->map[j - sz][ii][1] = value;
		ii++;
	}
	ii = ft_max(0, i - sz);
	while (j + sz < mstr->size[0] && ii <= ft_min(mstr->size[1] - 1, i + sz))
	{
		value = -(sz + ft_abs(i - ii));
		if ((mstr->map[j + sz][ii][1] < value) && (changed = 1))
			mstr->map[j + sz][ii][1] = value;
		ii++;
	}
	return (changed);
}

static int		ft_update_i(t_master *mstr, int i, int j, int sz)
{
	int jj;
	int changed;
	int value;

	changed = 0;
	jj = ft_max(0, j - sz);
	while (i - sz >= 0 && jj <= ft_min(mstr->size[0] - 1, j + sz))
	{
		value = -(sz + ft_abs(j - jj));
		if ((mstr->map[jj][i - sz][1] < value) && (changed = 1))
			mstr->map[jj][i - sz][1] = value;
		jj++;
	}
	jj = ft_max(0, j - sz);
	while (i + sz < mstr->size[1] && jj <= ft_min(mstr->size[0] - 1, j + sz))
	{
		value = -(sz + ft_abs(j - jj));
		if ((mstr->map[jj][i + sz][1] < value) && (changed = 1))
			mstr->map[jj][i + sz][1] = value;
		jj++;
	}
	return (changed);
}

static void		ft_parser_heatmap_update(t_master *mstr, int i, int j, int sz)
{
	int	changed;

	changed = 0;
	changed += ft_update_i(mstr, i, j, sz);
	changed += ft_update_j(mstr, i, j, sz);
	if (changed)
		ft_parser_heatmap_update(mstr, i, j, ++sz);
}

static void		ft_parser_heatmap_init(t_master *mstr)
{
	int i;
	int j;
	int *pos;
	int *pos_h;

	j = -1;
	while ((i = -1) && ++j < mstr->size[0])
	{
		while (++i < mstr->size[1])
		{
			pos = &mstr->map[j][i][0];
			pos_h = &mstr->map[j][i][1];
			*pos_h = *pos > 0 && mstr->heatmap_tg == 1 ? 1 : 0;
			*pos_h = *pos < 0 && mstr->heatmap_tg == 2 ? 1 : *pos_h;
			*pos_h = *pos == 0 && mstr->heatmap_tg ?
				-mstr->size[0] - mstr->size[1] : *pos_h;
		}
	}
}

void			ft_parser_heatmap(t_master *mstr)
{
	int i;
	int j;

	j = -1;
	ft_parser_heatmap_init(mstr);
	while ((i = -1) && ++j < mstr->size[0])
	{
		while (++i < mstr->size[1])
		{
			if (mstr->map[j][i][1] == 1)
				ft_parser_heatmap_update(mstr, i, j, 1);
		}
	}
}
