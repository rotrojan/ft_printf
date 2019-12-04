/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/03 22:53:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char(va_list args, t_spec *conv_spec)
{
	char	*str;
	char	*current;

	str = (char*)malloc(sizeof(str) * (conv_spec->min_field_width + 1));
	str[conv_spec->min_field_width] = '\0';
	current = str;
	if (conv_spec->padding == LEFT_PADDING)
	{
		*current = va_arg(args, int);
		while (current++)
			*current = ' ';
	}
	return (str);
}
