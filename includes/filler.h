/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:12:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 12:02:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#      include <stdio.h>

# define P1 1
# define P2 2

typedef struct			s_filler
{
	int			bszx;
	int			bszy;
	int			**board;
	int			pszx;
	int			pszy;
	char		**piece;
	int			answerx;
	int			answery;
}						t_filler;

#endif
