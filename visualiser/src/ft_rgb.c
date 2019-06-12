/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:38:39 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/10 14:31:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (256 * 256 * b + 256 * g + r);
}