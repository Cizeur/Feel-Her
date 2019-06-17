/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/17 12:14:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	exit_parser(t_filler *mst)
{
	if (mst->board)
		ft_parser_free_double_array((void ***)&mst->board);
	if (mst->piece)
		ft_parser_free_double_array((void ***)&mst->piece);
	ft_putstr("0 0\n");
	return (1);
}

int			parser(t_filler *mst)
{
	if (!mst->player && ft_parser_get_player(mst))
		return (exit_parser(mst));
	if (ft_parser_get_board_dims(mst))
		return (exit_parser(mst));
	if (ft_parser_get_board(mst))
		return (exit_parser(mst));
	if (ft_parser_get_piece_dims(mst))
		return (exit_parser(mst));
	if (ft_parser_get_piece(mst))
		return (exit_parser(mst));
	return (0);
}
