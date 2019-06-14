/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_player_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:06:12 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 16:06:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_parser_player_get(t_master *mstr,char *line)
{
	char *shorter;
	char **player;

	if (ft_strstr(line, EXEC_1_S))
		player = &mstr->player_1;
	else
		player = &mstr->player_2;
	if ((shorter = ft_strrchr(line, '[')))
		line = shorter + 1;
	if ((shorter = ft_strrchr(line, '/')))
		line = shorter + 1;
	if ((shorter = ft_strrchr(line, ']')))
		*shorter = 0;
	if ((shorter = ft_strrchr(line, '.')))
		*shorter = 0;
	*player = ft_strdup(line);
}
