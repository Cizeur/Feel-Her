/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 09:00:13 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	exit_parser(t_filler *mst)
{
	if (mst->board)
		ft_parser_free_double_array((void **)mst->board);
	if (mst->player_1)
		free(mst->player_1);
	if (mst->player_2)
		free(mst->player_2);
	if (mst->piece)
		ft_parser_free_double_array((void **)mst->piece);
	write(2, "map error\n", 10);
	return (1);
}

int			parser(t_filler *mst)
{
	if (ft_parser_get_board_dims(mst) || !mst->bszx || !mst->bszy)
		return (exit_parser(mst));
	if (ft_parser_get_board(mst))
		return (exit_parser(mst));
	return (0);
}
