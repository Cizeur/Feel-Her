/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:55:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 18:59:15 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void			ft_tracer(t_master *mstr)
{
	ft_tracer_grid_size(mstr, mstr->size);
	ft_tracer_grid(mstr, mstr->size);
	ft_tracer_grid_heatmap_fill(mstr, mstr->size);
	ft_tracer_grid_fill(mstr, mstr->size);
}
