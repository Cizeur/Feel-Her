/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 08:43:17 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 19:07:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static int		ft_loop_hook(t_master *mstr)
{
	if (mstr->updated != U_IDLE)
		ft_refresh(mstr);
	return (1);
}

static int		ft_close_click(t_master *mstr)
{
	ft_exit(STANDARD_EXIT, mstr);
	return (1);
}

static void		hook_loops(t_master *mstr)
{
	mlx_key_hook((mstr->mem_ptr)[WIN_PTR], ft_key_simple_press, mstr);
	mlx_hook((mstr->mem_ptr)[WIN_PTR], 2, 0, ft_key_loop, mstr);
	mlx_hook((mstr->mem_ptr)[WIN_PTR], 17, 0, ft_close_click, mstr);
	mlx_loop_hook((mstr->mem_ptr)[MLX_PTR], ft_loop_hook, mstr);
	mlx_expose_hook((mstr->mem_ptr)[WIN_PTR], ft_loop_hook, mstr);
}

int				main(int argc, char **argv)
{
	int			i;
	char		*line;
	t_master	*mstr;

	mstr = (t_master *)malloc(sizeof(t_master));
	if (!mstr)
		ft_exit(FAIL_MASTER, mstr);
	i = 0;
	line = 0;
	ft_init_mstr(mstr, 1);
	ft_init_resolution(mstr, argv, argc);
	ft_define_error_check(mstr);
	if (argc < 1 || argc > 3)
		ft_write_usage();
	else
	{
		ft_list_generate(mstr);
		ft_parser(mstr);
		ft_window_init(mstr->mem_ptr, mstr);
		ft_image_init(mstr->mem_ptr, mstr);
		hook_loops(mstr);
		mlx_loop((mstr->mem_ptr)[MLX_PTR]);
	}
	return (0);
}
