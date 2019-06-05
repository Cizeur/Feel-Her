/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generateur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:45:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/04 11:54:23 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int		random_int(int size)
{
	return(rand() % size);
}


int				main(int ac, char **av)
{
	int i;
	int j;
	int pos_o[2];
	int pos_x[2];

	srand(time(NULL) * 1000 + time(NULL)); 
	ac--;
	av++;
	if (ac != 2 || atoi(av[0]) <= 0 || atoi(av[1]) <= 0)
		printf ("./map_gen [ X Y ] (X et Y positif)\n");
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
		j = -1;
		while ((i = -1) && ++j < atoi(av[1]))
		{
			while (++i < atoi(av[0]))
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

}
