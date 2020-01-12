/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:51:21 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 10:37:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This lite implementation of the ft_atoi function will return an int value
** corresponding to the given string, but will return 0 in case of int max
** overflow, and does not handle negative numbers since the ft_printf "parsing"
** function has no need for that.
*/

int		ft_atoi_lite(char const *str)
{
	long int		result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str++ - '0';
		if (result > MAX_INT)
			return (0);
	}
	return (result);
}
