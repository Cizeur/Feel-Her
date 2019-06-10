/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:34:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/10 17:34:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_text_draw(t_master *mstr, int pos[2], int color, char *text)
{
	if (!text)
		return;
	mlx_string_put (mstr->mem_ptr[MLX_PTR],
	 mstr->mem_ptr[WIN_PTR], 
	 pos[0], pos[1],
	 color, text);
}
