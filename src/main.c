/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 10:07:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				printf("%d ", (*board)[i]);
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
		printf("mst->player_1 = %s\n", mst->player_1);
		printf("mst->player_2 = %s\n", mst->player_2);
	}
	else
		printf("nay :(\n");
	return (0);
}
