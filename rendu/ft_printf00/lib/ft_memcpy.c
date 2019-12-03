/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:56:51 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/24 15:58:19 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char		*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	while (n--)
		*tmp++ = *(unsigned char*)src++;
	return (dst);
}
