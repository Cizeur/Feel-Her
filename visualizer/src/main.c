/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 08:43:17 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/21 10:06:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_loop_hook(t_master *mstr)
{
	if (mstr->updated)
		ft_refresh(mstr);
	return(1);
}

void	hook_loops(t_master *mstr)
{
	mlx_key_hook((mstr->mem_ptr)[WIN_PTR], ft_key_simple_press, mstr);
	mlx_hook((mstr->mem_ptr)[WIN_PTR], 2, 0, ft_key_loop, mstr);
	mlx_loop_hook((mstr->mem_ptr)[MLX_PTR], ft_loop_hook, mstr);
	mlx_expose_hook((mstr->mem_ptr)[WIN_PTR],ft_loop_hook, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 4, 0, ft_mouse_pressed, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 5, 0, ft_mouse_released, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 6, 0, ft_mouse_moved, mstr);
}

int		main(int argc, char **argv)
{
	int			i;
	char		*line;
	t_master	*mstr;
	t_master	mstr_val;

	mstr = &mstr_val;
	i = 0;
	line = 0;
	ft_init_mstr(mstr);
	ft_init_resolution(mstr, argv, argc);
	if (argc < 1 || argc > 3)
		ft_write_usage();
	else
	{
		ft_init_window(mstr->mem_ptr, mstr);
		ft_image_fresh(mstr->mem_ptr, mstr);
		ft_list_generate(mstr);
		ft_refresh(mstr);
		hook_loops(mstr);
		mlx_loop((mstr->mem_ptr)[MLX_PTR]);
	}
	return (0);
}
