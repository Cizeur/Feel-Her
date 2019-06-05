/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:12:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 15:23:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
#      include <stdio.h>

# define P_O 1
# define P_X 2
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
	int			player;
	char		*player_1;
	char		*player_2;
}				t_filler;

/*
** PROTOTYPE ZONE START
*/

void			sub_solver(t_filler *mfill);
void			ft_solver_heatmap(t_filler *mfill);
void			ft_parser_free_double_array(void **arr);
void			**ft_parser_alloc_double_array(int x, int y, size_t size);

/*
** PROTOTYPE ZONE END
*/
#endif
