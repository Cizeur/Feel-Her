/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/13 14:55:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler	master;
	t_filler	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filler));
	while (!parser(mst))
	{
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
