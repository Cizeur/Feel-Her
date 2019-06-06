/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:12:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/06 09:40:45 by yforeau          ###   ########.fr       */
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
	int			adv;
	int			best_score;
}				t_filler;

/*
** PROTOTYPE ZONE START
*/

void			sub_solver(t_filler *mfill);
void			ft_solver_heatmap_init(t_filler *mfill, int i, int j);
void			ft_solver_heatmap(t_filler *mfill, int i, int j);
void			ft_solver_check_score(t_filler *mf, int i, int j);
int				ft_intlen(intmax_t n);
int				parser(t_filler *mst);
void			ft_parser_free_double_array(void **arr);
void			**ft_parser_alloc_double_array(int x, int y, size_t size);
void			ft_parser_get_dims(char *dims, int *x, int *y);
int				ft_parser_get_board_dims(t_filler *mst);
int				ft_parser_get_board(t_filler *mst);
int				ft_parser_get_piece_dims(t_filler *mst);
int				ft_parser_get_piece(t_filler *mst);
void			ft_solver_tab_skim(t_filler *mf, void (*f)(t_filler *mf, int i, int j));

/*
** PROTOTYPE ZONE END
*/
#endif
