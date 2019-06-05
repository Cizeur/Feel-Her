/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:48:48 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 15:05:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	get_dims(char *dims, int *x, int *y)
{
	*y = ft_atoi(dims);
	while (*dims && *dims > 47 && *dims < 58)
		++dims;
	*x = ft_atoi(dims);
}

int			get_board_dims(t_filler *mst)
{
	char	*line;
	int		c;
	int		r;

	c = 0;
	line = NULL;
	while ((r = get_next_list_single_fd(0, &line)) > 0)
	{
		if (line[0] == '<' && !c || line[0] == '#')
			free(line);
		else if (!ft_strncmp(line, "Plateau ", 8) && c)
			break ;
		else
		{
			free(line);
			return (1);
		}
		++c;
	}
	if (r < 0 || !line)
		return (1);
	get_dims(line + 8, &mst->bszx, &mst->bszy);
	free(line);
	return (0);
}
