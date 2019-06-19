/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:21:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:55:31 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include <mlx.h>

void			ft_image_dump(void **mem_ptr)
{
	mlx_put_image_to_window(mem_ptr[MLX_PTR], mem_ptr[WIN_PTR],
			mem_ptr[I_PTR], 0, 0);
}
