/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:54:21 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/30 22:51:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strnlen(char const *s, size_t maxlen)
{
	char	*tmp;

	tmp = (char*)s;
	while (maxlen-- && *tmp)
		tmp++;
	return ((size_t)(tmp - s));
}

static char			*ft_strndup(const char *s1, size_t n)
{
	char			*str;
	size_t			maxlen;

	if (!s1)
		return (NULL);
	maxlen = ft_strnlen(s1, n);
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	str = ft_memcpy(str, s1, maxlen);
	*(str + maxlen) = '\0';
	return (str);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(str = ft_strndup(s + start, len)))
		return (NULL);
	return (str);
}
