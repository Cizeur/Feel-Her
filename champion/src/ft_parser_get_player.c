/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:36:22 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/17 12:14:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int	ft_parser_get_player(t_filler *mst)
{
	int		r;
	char	*ptr;
	char	*line;

	line = NULL;
	if ((r = get_next_line(0, &line)) > 0
		&& !ft_strncmp(line, "$$$ exec p", 10)
		&& (line[10] == '1' || line[10] == '2')
		&& !ft_strncmp(line + 11, " : [", 3)
		&& ft_strlen(line + 15) >= 2
		&& (ptr = ft_strchr(line + 15, ']'))
		&& !ptr[1])
		mst->player = line[10] == '1' ? P_O : P_X;
	if (r >= 0)
		free(line);
	return (!mst->player);
}
