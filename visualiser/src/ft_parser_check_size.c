/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:27:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:35:05 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include "libft/libft.h"

void		ft_check_too_big(t_master *mstr, int *size)
{
	if (size[1] >= (mstr->xres - 1) * FILL_PERCENT / 100
		|| size[0] >= (mstr->yres - TOP_ROW_THICKNESS - 1) * FILL_PERCENT / 100)
		ft_exit(FAIL_WINDOW_TO_SMALL, mstr);
}

int			ft_parser_check_size(t_master *mstr, char *line, int *size)
{
	char *number;

	if (size[0] != -1 && size[1] != -1)
		return (1);
	if (!(number = ft_strchr(line, ' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[0] = ft_atoi(number + 1);
	*number = '|';
	if (!(number = ft_strchr(line, ' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[1] = ft_atoi(number + 1);
	ft_check_too_big(mstr, size);
	return (1);
}
