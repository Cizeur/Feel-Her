/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 15:18:48 by yforeau          ###   ########.fr       */
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
		printf("%d %d\n", mst->answery, mst->answerx);
		if (mst->board)
		{
			ft_parser_free_double_array((void **)mst->board);
			mst->board = NULL;
		}
		if (mst->piece)
		{
			ft_parser_free_double_array((void **)mst->piece);
			mst->piece = NULL;
		}
		sleep(5);
	}
	return (0);
}
/*
int	main(void)
{
	t_filler	master;
	t_filler	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filler));
	if (!parser(mst))
	{
		printf("YAAAAAAAY!!!!!\n\n");
		printf("bszx = %d\n", mst->bszx);
		printf("bszy = %d\n", mst->bszy);
		int	**board = mst->board;
		while (*board)
		{
			for (int i = 0; i < mst->bszx; i++)
			{
				switch ((*board)[i])
				{
					case 1:
						printf(C_RED"1 "C_RESET);
						break ;
					case 2:
						printf(C_GREEN"2 "C_RESET);
						break ;
					default:
						printf(C_MAGENTA"3 "C_RESET);
						break ;
				}
			}
			printf("\n");
			++board;
		}
		printf("\npszx = %d\n", mst->pszx);
		printf("pszy = %d\n", mst->pszy);
		char	**piece = mst->piece;
		while (*piece)
		{
			for (int i = 0; i < mst->pszx; i++)
				printf("%c", (*piece)[i]);
			printf("\n");
			++piece;
		}
		printf("\nanswerx = %d\n", mst->answerx);
		printf("answery = %d\n", mst->answery);
		printf("mst->player = %s\n", mst->player == P_O ? "P_O" : "P_X");
	}
	else
		printf("nay :(\n");
	return (0);
}*/
