/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:45:45 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/28 16:32:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_tab(int n, unsigned char size, char **str)
{
	(*str)[--size] = '\0';
	if (n < 0)
	{
		(*str)[0] = '-';
		n = -n;
	}
	while (n)
	{
		(*str)[--size] = n % 10 + '0';
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	unsigned char	size;
	int				tmp;
	char			*str;

	if (!n)
		str = ft_strdup("0");
	else if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
	{
		size = n < 0 ? 2 : 1;
		tmp = n;
		while (tmp)
		{
			tmp /= 10;
			size++;
		}
		if (!(str = (char*)malloc(sizeof(*str) * (size))))
			return (NULL);
		fill_tab(n, size, &str);
	}
	return (str);
}
