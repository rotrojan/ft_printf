/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:51:01 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/28 16:52:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	if ((unsigned char*)dst < (unsigned char*)src)
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	else
		while (len--)
			*((unsigned char*)dst + len) = *((unsigned char*)src + len);
	return (dst);
}
