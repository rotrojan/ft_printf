/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:11:47 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/29 23:38:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	is_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		i;

	if (!s1)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	if (!set || !*set)
		return (ft_strdup(s1));
	i = 0;
	while (is_set(*(s1 + i), set))
		i++;
	start = i;
	while (*(s1 + i))
		i++;
	while (is_set(*(s1 + i - 1), set))
	{
		i--;
		if (!i)
			return (ft_strdup(""));
	}
	return (ft_substr(s1, start, i - start));
}
