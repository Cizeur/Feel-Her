/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_free_board.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:00:10 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 15:04:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_parser_free_board(int **board)
{
	int	*ptr;

	ptr = board;
	while (*ptr)
		free(*ptr++);
	free(board);
}
