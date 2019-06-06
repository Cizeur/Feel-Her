/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_heatmap_gen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:14:41 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 14:14:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_solver_heatmap_init(t_filler *mfill)
{
	int **board;
	int bszx;
	int bszy;

	bszx = mfill->bszx;
	bszy = mfill->bszy;
	board = mfill->board;
	while ((bszx = mfill->bszx) && bszy--)
	{
		while (bszx--)
		{
			if (board[bszy][bszx] == P_EMPTY)
				board[bszy][bszx] = - (mfill->bszx + mfill->bszy);
		}
	}
}

static int		ft_update_j(t_filler *mf, int i, int j, int sz)
{
	int ii;
	int changed;
	int value;
	
	changed = 0;
	ii = ft_max(0, i - sz);
	while ( j - sz >= 0 && ii <= ft_min(mf->bszx - 1, i + sz))
	{
		value = -(sz + ft_abs(i - ii));
		if ((mf->board[j - sz][ii] < value) && (changed = 1))
			mf->board[j - sz][ii] = value;
		ii++;
	}
	ii = ft_max(0, i - sz);
	while ( j + sz < mf->bszy && ii <= ft_min(mf->bszx - 1, i + sz))
	{
		value = -(sz + ft_abs(i - ii));
		if ((mf->board[j + sz][ii] < value) && (changed = 1))
			mf->board[j + sz][ii] = value;
		ii++;
	}
	return(changed);
}

static int		ft_update_i(t_filler *mf, int i, int j, int sz)
{
	int jj;
	int changed;
	int value;

	changed = 0;
	jj = ft_max(0, j - sz);
	while ( i - sz >= 0 && jj <= ft_min(mf->bszy - 1, j + sz))
	{
		value = -(sz + ft_abs(j - jj));
		if ((mf->board[jj][i - sz] < value) && (changed = 1))
			mf->board[jj][i -sz] = value;
		jj++;
	}
	jj = ft_max(0, j - sz);
	while ( i + sz < mf->bszx && jj <= ft_min(mf->bszy - 1, j + sz))
	{
		value = -(sz + ft_abs(j - jj));
		if ((mf->board[jj][i + sz] < value) && (changed = 1))
			mf->board[jj][i + sz] = value;
		jj++;
	}
	return(changed);
}

static void		ft_solver_heatmap_update(t_filler *mf, int i, int j, int sz)
{
	int	changed;

	changed = 0;
	changed += ft_update_i(mf,i ,j ,sz);
	changed += ft_update_j(mf,i ,j ,sz);
	if (changed)
		ft_solver_heatmap_update(mf,i ,j ,++sz);
}

void			ft_solver_heatmap(t_filler *mfill)
{
	int **board;
	int bszx;
	int bszy;

	bszx = mfill->bszx;
	bszy = mfill->bszy;
	board = mfill->board;
	ft_solver_heatmap_init(mfill);
	while ((bszx = mfill->bszx) && bszy--)
	{
		while (bszx--)
		{
			if (board[bszy][bszx] == (mfill->player == P_O ? P_X : P_O))
				ft_solver_heatmap_update(mfill, bszx, bszy ,1);
		}
	}
}
