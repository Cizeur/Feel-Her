/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generateur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:45:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/18 08:55:04 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int		random_int(int size)
{
	return (rand() % size);
}

static void		print_map(int pos_o[2], int pos_x[2], int size_x, int size_y)
{
	int i;
	int j;

	j = -1;
	while ((i = -1) && ++j < size_y)
	{
		while (++i < size_x)
		{
			if ((pos_o[0] == i && pos_o[1] == j))
				printf("O");
			else if ((pos_x[0] == i && pos_x[1] == j))
				printf("X");
			else
				printf(".");
		}
		printf("\n");
	}
}

int				main(int ac, char **av)
{
	int pos_o[2];
	int pos_x[2];

	srand(time(NULL) * 1000 + time(NULL));
	ac--;
	av++;
	if (ac != 2 || atoi(av[0]) <= 2 || atoi(av[1]) <= 2)
		return (0);
	else
	{
		pos_o[0] = random_int(atoi(av[0]));
		pos_o[1] = random_int(atoi(av[1]));
		pos_x[0] = random_int(atoi(av[0]));
		pos_x[1] = random_int(atoi(av[1]));
		while (pos_o[0] == pos_x[0] && pos_o[1] == pos_x[1])
		{
			pos_x[0] = random_int(atoi(av[0]));
			pos_x[1] = random_int(atoi(av[1]));
		}
		print_map(pos_o, pos_x, atoi(av[0]), atoi(av[1]));
	}
	return (0);
}
