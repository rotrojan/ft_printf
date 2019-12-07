/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/05 22:01:02 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*convert_char(va_list args, t_spec *conv_spec)
{
	char	*str;
	char	*current;

	if (!(str = (char*)malloc(sizeof(str) * (conv_spec->min_field_width + 1))))
		return (0);
	ft_bzero(str, conv_spec->min_field_width + 1);
	current = str;
	if (conv_spec->padding == LEFT_PADDING)
	{
		*(current++) = va_arg(args, int);
		while (current - str < conv_spec->min_field_width)
			*(current++) = '0';
	}
//	else if (conv_spec->padding == )
	return (str);
}
