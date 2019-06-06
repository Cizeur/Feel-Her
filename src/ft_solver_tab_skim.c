/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tab_skim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:01:13 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/06 10:30:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_solver_tab_skim(t_filler *mf, void (*f)(t_filler *mf, int i, int j))
{
	int **board;
	int bszx;
	int bszy;

	bszx = mf->bszx;
	bszy = mf->bszy;
	board = mf->board;
	while ((bszx = mf->bszx) && bszy--)
	{
		while (bszx--)
		{
			(*f)(mf, bszx, bszy);
		}
	}
}
