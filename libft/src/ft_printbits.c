/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:31:20 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:31:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printbits(long long int byte, int size)
{
	long long int	i;
	int				sep;

	sep = size;
	i = 1;
	while (--size)
		i = 2 * i;
	while (i > 0)
	{
		if (byte & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
		sep--;
		if (i && !(sep % 8))
			write(1, " ", 1);
	}
}
