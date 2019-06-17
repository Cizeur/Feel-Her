/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:04:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 08:04:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_chr_counter(char *str, char c)
{
	int count;

	if (!str || !c)
		return (0);
	count = 0;
	while (*str)
		count += *(str++) == c ? 1 : 0;
	return (count);
}
