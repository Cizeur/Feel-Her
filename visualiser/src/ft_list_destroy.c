/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:22:36 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:55:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void		ft_list_destroy(t_list **output)
{
	t_list *stock;

	while (*output)
	{
		stock = (*output)->next;
		if ((*output)->content)
		{
			free((*output)->content);
			(*output)->content = NULL;
		}
		(*output)->content_size = 0;
		free(*output);
		*output = stock;
	}
}
