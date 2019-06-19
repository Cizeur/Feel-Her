/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:34:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:34:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_splitn(char const *s, char c, size_t *sz, size_t n)
{
	char		*word;
	char		**splitted;
	size_t		wl;

	while (!(wl = 0) && *s == c)
		s++;
	while (!(word = 0) && s[wl] && (s[wl] != c || *sz >= n))
		wl++;
	(*sz)++;
	if (wl)
	{
		if (!(word = ft_strnew(wl)))
			return (!(sz = 0) ? NULL : NULL);
		ft_strncpy(word, s, wl);
		splitted = ft_splitn(s + wl, c, sz, n);
	}
	else
		splitted = (char **)malloc(sizeof(char *) * (*sz));
	if (splitted && (*sz))
		splitted[--(*sz)] = word;
	else
		free(word);
	return (splitted);
}

char			**ft_strsplitn(char const *s, char c, size_t n)
{
	size_t			sz;

	if (!s)
		return (NULL);
	sz = 0;
	return (ft_splitn(s, c, &sz, n));
}
