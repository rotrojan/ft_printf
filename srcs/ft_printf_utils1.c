/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:53:34 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/09 22:27:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_lite(char const *str)
{
	int		result;

	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + *(str++) - '0';
	return (result);
}

size_t		ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		ft_bzero(void *b, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)b;
	while (n--)
		*(unsigned char*)tmp++ = 0;
}
