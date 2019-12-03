/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:53:40 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/26 11:27:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	if (!c)
		return ((char*)s + len);
	while (len--)
		if (*(s + len) == c)
			return ((char*)(s + len));
	return (NULL);
}
