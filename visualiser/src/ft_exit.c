/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:24:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 10:50:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static void			ft_free_all(t_master *mstr)
{
	ft_list_destroy(&(mstr->output));
	mstr->current = NULL;
	if ((mstr->mem_ptr)[WIN_PTR] && (mstr->mem_ptr)[MLX_PTR])
		mlx_destroy_window((mstr->mem_ptr)[MLX_PTR], (mstr->mem_ptr)[WIN_PTR]);
	if ((mstr->mem_ptr)[MLX_PTR] && (mstr->mem_ptr)[I_PTR])
		mlx_destroy_image(mstr->mem_ptr[MLX_PTR], mstr->mem_ptr[I_PTR]);
	if (mstr->player_1)
		ft_memdel((void**)&(mstr->player_1));
	if (mstr->player_2)
		ft_memdel((void**)&(mstr->player_2));
}

static void			ft_error_message(int code, t_master *mstr)
{
	if (code == STANDARD_EXIT)
		return ;
	ft_putstr("\e[31m");
	if (code == FAIL_WINDOW_TO_SMALL)
	{
		ft_putstr("Window to small (TOP YBAR = 100): ");
		ft_putstr(mstr->current_line);
	}
	if (code <= 4 && code >= 1)
		ft_putstr("Fail de malloc ");
	if (code == FAIL_ERROR)
		ft_putstr("Fail Error ou Abort : ");
	if (code == FAIL_READING)
		ft_putstr("Read Problem : ");
	if (code == FAIL_LINE_LEN || code == FAIL_LINE_TO_LONG)
		ft_putstr("Check Plateau or line length : ");
	if (code >= 4 && code <= 10)
		ft_putnbr(mstr->read_lines);
	ft_putstr("\n");
	ft_putstr("\e[39m");
}

void				ft_exit(int code, t_master *mstr)
{
	if (mstr)
		ft_free_all(mstr);
	ft_error_message(code, mstr);
	if (code == STANDARD_EXIT)
		exit(0);
	exit(1);
}
