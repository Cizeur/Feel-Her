/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:50:03 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 13:53:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler_visualiser.h>

static int	ft_rainbow(int val, int amp)
{
	int col;
	int r;
	int g;
	int b;

	col = amp ? COLOR_AMP - val * (COLOR_AMP) / amp : COLOR_AMP;
	b = col <= 255 ? 255 : 0;
	g = col <= 255 ? col : 0;
	r = 0;
	b = col <= 510 && col > 255 ? 510 - col : b;
	g = col <= 510 && col > 255 ? 255 : g;
	g = col <= 765 && col > 510 ? 255 : g;
	r = col <= 765 && col > 510 ? col - 510 : 0;
	g = col <= 1020 && col > 765 ? 1020 - col : g;
	r = col <= 1020 && col > 765 ? 255 : r;
	r = col <= 1275 && col > 1020 ? 255 : r;
	b = col <= 1275 && col > 1020 ? col - 1020 : b;
	return (ft_rgb(r, g, b));
}

static int	ft_color_grad(int val, int amp, int color_tg)
{
	int graded;

	
	graded = amp ? (val * 205) / amp + 45 : 250;
	if (color_tg == 0)
		return (ft_rgb(graded, 0, 0));
	else if (color_tg == 1)
		return (ft_rgb(0, graded, 0));
	else if (color_tg == 2)
		return (ft_rgb(0, 0, graded));
	else if (color_tg == 3)
		return (ft_rgb(graded, 0, graded));
	else if (color_tg == 4)
		return (ft_rgb(0, graded, graded));
	else if (color_tg == 5)
		return (ft_rgb(graded, graded, 0));
	else if (color_tg == 6)
		return (ft_rainbow(val, amp));
	return (ft_rgb(graded, graded, graded));
}

static int	ft_one_color(int color_tg)
{
	if (color_tg == 0)
		return (ft_rgb(255, 0, 0));
	else if (color_tg == 1)
		return (ft_rgb(0, 255, 0));
	else if (color_tg == 2)
		return (ft_rgb(0, 0, 255));
	else if (color_tg == 3)
		return (ft_rgb(255, 0, 255));
	else if (color_tg == 4)
		return (ft_rgb(0, 255, 255));
	else if (color_tg == 5)
		return (ft_rgb(255, 255, 0));
	else if (color_tg == 6)
		return (ft_rgb(0, 0, 0));
	return (ft_rgb(255, 255, 255));
}

int			ft_color_gradient(int val, int amp, int color_tg, int gradient_tg)
{
	if (!gradient_tg)
		return (ft_one_color(color_tg));
	return (ft_color_grad(val, amp, color_tg));
}
