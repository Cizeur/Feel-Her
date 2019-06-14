/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:27:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 14:27:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

int		ft_parser_check_size(char *line, int *size)
{
	char *number;
	if (size[0] != -1 && size[1] != -1)
		return (1);
	if (!(number = ft_strchr(line,' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[0] = ft_atoi(number + 1);
	*number = '|';
	if (!(number = ft_strchr(line,' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[1] = ft_atoi(number + 1);
	return(1);
}
