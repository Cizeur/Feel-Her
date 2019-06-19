/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:33:31 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:33:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	len++;
	i = -1;
	if (len == 0)
		return (dst);
	while (src[++i] && --len > 0)
		dst[i] = src[i];
	if (len)
		ft_bzero(dst + i, len - 1);
	return (dst);
}
