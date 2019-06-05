/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_alloc_double_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:20:08 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 15:24:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	**ft_parser_alloc_double_array(int x, int y, size_t size)
{
	void	**arr;
	int		i;

	if (!(arr = (void **)malloc((y + 1) * sizeof(void *))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (!(arr[i++] = (void *)malloc((x + 1) * size)))
		{
			ft_parser_free_double_array(arr);
			return (NULL);
		}
	}
	return (arr);
}
