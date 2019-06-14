/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_text_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:20:45 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 14:20:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void	ft_window_text_draw(t_master *mstr, int pos[2], int color, char *text)
{
	if (!text)
		return;
	mlx_string_put (mstr->mem_ptr[MLX_PTR],
	 mstr->mem_ptr[WIN_PTR], 
	 pos[0], pos[1],
	 color, text);
}
