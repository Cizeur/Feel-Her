/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:11:12 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 12:11:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			sub_solver(t_filler *mfill)
{
	mfill->adv = mfill->player == P_O ? P_X : P_O;
	mfill->best_score  = 0;
	ft_solver_tab_skim(mfill, &ft_solver_heatmap_init);
	ft_solver_tab_skim(mfill, &ft_solver_heatmap);
	ft_solver_tab_skim(mfill, &ft_solver_check_score);
}
