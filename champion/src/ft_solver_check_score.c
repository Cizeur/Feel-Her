/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_check_score.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:37:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 17:51:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_update_solution(t_filler *mf, int score, int i, int j)
{
	mf->best_sc = score;
	mf->answerx = i;
	mf->answery = j;
}

int				ft_only_one_adversary(t_filler *mf, int i, int j)
{
	int cov_piece;
	int	score;
	int ii;
	int jj;

	score = 0;
	cov_piece = 0;
	jj = -1;
	while ((ii = -1) && ++jj < mf->pszy)
	{
		while (++ii < mf->pszx)
		{
			if (mf->piece[jj][ii] != '*')
				continue;
			cov_piece += mf->board[j + jj][i + ii] == mf->player ? 1 : 0;
			if (mf->board[j + jj][i + ii] == mf->adv || cov_piece > 1 ||
					mf->board[j + jj][i + ii] == P_OBS)
				return (0);
			score += mf->board[j + jj][i + ii];
		}
	}
	if (cov_piece != 1 || (score < mf->best_sc && mf->best_sc && mf->alone))
		return (0);
	ft_update_solution(mf, score, i, j);
	return (1);
}

void			ft_solver_check_score(t_filler *mf, int i, int j)
{
	if (i + mf->pszx > mf->bszx || j + mf->pszy > mf->bszy)
		return ;
	if (!ft_only_one_adversary(mf, i, j))
		return ;
	mf->board[j][i] = mf->board[j][i] < 0 ? 4 : mf->board[j][i];
}
