/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:55 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/24 16:42:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char*)src) == (unsigned char)c)
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			return (dst + 1);
		}
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	return (NULL);
}
