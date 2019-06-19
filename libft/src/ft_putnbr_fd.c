/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:32:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:33:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ns;

	ns = n;
	if (ns < 0)
	{
		ns = -ns;
		ft_putchar_fd('-', fd);
	}
	if (ns < 10)
	{
		ft_putchar_fd('0' + ns, fd);
		return ;
	}
	ft_putnbr_fd(ns / 10, fd);
	ft_putnbr_fd(ns % 10, fd);
}
