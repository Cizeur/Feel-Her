/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_free_double_array.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:20:18 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 15:24:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_parser_free_double_array(void **arr)
{
	void	**ptr;

	ptr = arr;
	while (*ptr)
		free(*ptr++);
	free(arr);
}
