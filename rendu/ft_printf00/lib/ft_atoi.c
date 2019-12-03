/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:51:21 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/29 22:20:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		result;
	char	is_negative;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	is_negative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + *(str++) - '0';
	return (result * is_negative);
}
