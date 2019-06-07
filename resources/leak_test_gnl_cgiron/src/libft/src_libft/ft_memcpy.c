/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:48:18 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:11:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dchar;
	const unsigned char *schar;

	i = 0;
	dchar = (unsigned char *)dst;
	schar = (const unsigned char*)src;
	while (i < n)
	{
		dchar[i] = schar[i];
		i++;
	}
	return (dst);
}
