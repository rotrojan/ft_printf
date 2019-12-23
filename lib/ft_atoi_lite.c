/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:51:21 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/23 06:35:57 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define INT_MAX 2147483647

int		ft_atoi_lite(char const *str)
{
	int		result;
	int		overflow;

	result = 0;
	overflow = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + *str++ - '0';
		overflow++;
		if (overflow == 9)
			return (0);
	}
	return (result);
}
