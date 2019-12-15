/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:51:21 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/15 08:51:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_lite(char const *str)
{
	int		result;

	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + *str++ - '0';
	return (result);
}
