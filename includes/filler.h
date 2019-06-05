/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:12:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/05 11:12:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#      include <stdio.h>

typedef struct			s_filler
{
	int			bszx;
	int			bszy;
	char		**board;
	int			pszx;
	int			pszy;
	char		**piece;
}						t_filler;

#endif