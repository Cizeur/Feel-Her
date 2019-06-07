/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/07 09:17:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#	include "c_colors.h"

int	main(void)
{
	t_filler	master;
	t_filler	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filler));
	while (!parser(mst))
	{
		sub_solver(mst);
		ft_putnbr(mst->answery);
		ft_putchar(' ');
		ft_putnbr(mst->answerx);
		ft_putchar('\n');
		if (mst->board)
			ft_parser_free_double_array((void ***)&mst->board);
		if (mst->piece)
			ft_parser_free_double_array((void ***)&mst->piece);
	}
	return (0);
}
