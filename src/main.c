/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/13 14:49:15 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#	include "c_colors.h"

#	include <stdio.h>
#	include <fcntl.h>

void	write_mst(t_filler *mst)
{
	int	fd;

	fd = 2;
	dprintf(fd, "bszx=%d", mst->bszx);
	dprintf(fd, "\nbszy=%d", mst->bszy);
	dprintf(fd, "\npszx=%d", mst->pszx);
	dprintf(fd, "\npszy=%d", mst->pszy);
	dprintf(fd, "\nanswerx=%d", mst->answerx);
	dprintf(fd, "\nanswery=%d", mst->answery);
	dprintf(fd, "\nplayer=%s", mst->player == P_O ? "P_O" : "P_X");
	dprintf(fd, "\nadv=%s", mst->adv == P_O ? "P_O" : "P_X");
	dprintf(fd, "\nbest_score=%d", mst->best_score);
	dprintf(fd, "\nround=%d", mst->round);
	dprintf(fd, "\nalone=%d\n", mst->alone);
}


int	main(void)
{
	t_filler	master;
	t_filler	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filler));
	while (!parser(mst))
	{
	//	write_mst(mst);	//debug
		mst->answerx = 0;
		mst->answery = 0;
		sub_solver(mst);
		ft_putnbr(mst->answery);
		ft_putchar(' ');
		ft_putnbr(mst->answerx);
		ft_putchar('\n');
		if (mst->board)
			ft_parser_free_double_array((void ***)&mst->board);
		if (mst->piece)
			ft_parser_free_double_array((void ***)&mst->piece);
		++mst->round;
	}
	return (0);
}
