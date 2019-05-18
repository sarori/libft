/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:57:13 by sapark            #+#    #+#             */
/*   Updated: 2019/05/17 20:36:23 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	int				len;
	int				start;
	char			**res;

	if (!s)
		return (NULL);
	if (!(res = ft_sizecount(s, c)))
		return (NULL);
	start = 0;
	i = 0;
	len = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if (s[i] != c && s[i + 1] == c)
			res[len++] = ft_strsub(s, start, i - start + 1);
		if (i + 2 == ft_strlen(s) && s[i + 1] != c)
			res[len++] = ft_strsub(s, start, i - start + 2);
		i++;
	}
	res[len] = ((void *)0);
	return (res);
}
