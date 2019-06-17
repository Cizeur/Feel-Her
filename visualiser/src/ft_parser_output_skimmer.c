/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_output_skimmer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:03:25 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 15:03:27 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_parser_output_skimmer(t_master *mstr, int *size)
{
	char	line[BUFFER_LINE];
	int		size_check;

	size_check = 1;
	while (mstr->still_reading && size_check && ft_parser_gnl(mstr, line))
	{
		ft_parser_special_cases(mstr, line);
		if (line == ft_strstr(line, PLATEAU_S))
		{
				if ((size_check = ft_parser_check_size(mstr, line, size)))
				size_check = ft_parser_map_update(mstr,size);
			break;
		}
	}
	if (!size_check || size[0] <= 0)
		ft_exit(FAIL_LINE_LEN, mstr);
}
