/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_alloc_double_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:20:08 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/07 07:13:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	**ft_parser_alloc_double_array(int x, int y, size_t size)
{
	void	**arr;
	int		i;

	if (!(arr = (void **)ft_memalloc((y + 1) * sizeof(void *))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (!(arr[i++] = (void *)ft_memalloc((x + 1) * size)))
		{
			ft_parser_free_double_array(&arr);
			return (NULL);
		}
	}
	arr[y] = NULL;
	return (arr);
}
