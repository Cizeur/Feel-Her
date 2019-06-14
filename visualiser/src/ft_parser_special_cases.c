/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_special_cases.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:04:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 16:04:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void ft_parser_special_cases(t_master *mstr, char *line)
{
	if (line == ft_strstr(line, INVERT))
		ft_swap(&(mstr->color_1_tg), &(mstr->color_2_tg));
	else if (ft_strstr(line, END_S))
		mstr->still_reading = 0;
	else if (ft_strstr(line, EXEC_1_S) || ft_strstr(line, EXEC_2_S))
			ft_parser_player_get(mstr, line);
}