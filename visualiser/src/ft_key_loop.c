/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:53:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:48:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

int				ft_key_loop(int key, t_master *mstr)
{
	mstr->updated = key == SPACEBAR ? 2 : mstr->updated;
	if (mstr->updated)
		ft_refresh(mstr);
	return (key);
}
