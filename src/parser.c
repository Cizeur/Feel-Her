/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 13:56:58 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_dims.h"

static int	exit_parser(void)
{
	write(1, "map error\n", 10);
	return (1);
}

static int	get_board(t_filler *mst)
{
	
}

int			parser(t_filler *mst)
{
	if (get_board_dims(mst) || !mst->bszx || !mst->bszy)
		return (exit_parser());
	if (get_board(mst))
		return (exit_parser());
}
