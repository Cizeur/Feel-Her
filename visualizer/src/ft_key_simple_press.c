/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_simple_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:46:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 10:22:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_key_simple_press(int key, t_master *mstr)
{
	key != 53 ? key = key + 0 : ft_exit(STANDARD_EXIT, mstr);
	return (key);
}
