/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_fresh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:25:00 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/13 12:26:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_image_fresh(void **mem_ptr, t_master *mstr)
{
	int data_prm[3];

	mem_ptr[I_PTR] = mlx_new_image(mem_ptr[MLX_PTR], mstr->xres, mstr->yres);
	if (!mem_ptr[I_PTR])
		ft_exit(FAIL_IMAGE_CREATION, mstr);
	mem_ptr[I_ADR] = mlx_get_data_addr(mem_ptr[I_PTR],
			&(data_prm[0]), &(data_prm[1]), &(data_prm[2]));
}
