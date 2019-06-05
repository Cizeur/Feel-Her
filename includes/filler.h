/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:12:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 15:05:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
#      include <stdio.h>

# define P_ME 1
# define P_OP 2
# define P_EMPTY 3

/*
** Pour les tableaux premiere dimension y, seconde dimension x
*/

typedef struct	s_filler
{
	int			bszx;
	int			bszy;
	int			**board;
	int			pszx;
	int			pszy;
	char		**piece;
	int			answerx;
	int			answery;
}				t_filler;

/*
** PROTOTYPE ZONE START
*/

void			sub_solver(t_filler *mfill);
void			ft_solver_heatmap(t_filler *mfill);
void			ft_parser_free_board(int **board)

/*
** PROTOTYPE ZONE END
*/
#endif
