/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_dims.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:50:25 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 09:07:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parser_get_dims(char *dims, int *x, int *y)
{
	*y = ft_atoi(dims);
	while (*dims && *dims > 47 && *dims < 58)
		++dims;
	*x = ft_atoi(dims);
}
