/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:42:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/11 14:42:21 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_list_generate(t_master *mstr)
{
	int		r;
	t_list	*output;
	char 	buffer[MAX_XRES + 1];

	output = NULL;
	ft_bzero(buffer, MAX_XRES + 1);
	mstr->read_lines = 0;
	while((r = read(0, buffer, MAX_XRES)) > 0)
	{
		mstr->read_lines++;
		output = ft_lstaddend(output, buffer, ft_strlen(buffer) + 1);
		if (output)
			mstr->output = output;
		else
			ft_exit(FAIL_LISTING, mstr);
		ft_bzero(buffer, MAX_XRES + 1);
	}
	mstr->read_lines = 0;
	mstr->current = mstr->output;
}
