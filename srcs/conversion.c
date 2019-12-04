/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/04 03:47:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(char **fmt, t_spec *conv_spec)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (conv_spec->padding == RIGHT_PADDING)
		{
			if (**fmt == '-')
				conv_spec->padding = LEFT_PADDING;
			else if (**fmt == '0')
				conv_spec->padding = ZERO_PADDING;
		}
		else if (conv_spec->padding == ZERO_PADDING)
			if (**fmt == '-')
				conv_spec->padding = LEFT_PADDING;
		(*fmt)++;
	}
}

int		parsing(char *fmt, t_spec *conv_spec, char **segment)
{
	char	*conversion;

	conversion = NULL;
	parse_flags(&fmt, conv_spec);
	conv_spec->min_field_width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '.')
	{
		conv_spec->precision = ft_atoi(++fmt);
		while (ft_isdigit(*fmt))
			fmt++;
	}
	if (!(conversion = ft_strchr(g_str_conversion, *fmt)))
		return (-1);
	*segment = ++fmt;
	return (conversion - g_str_conversion);
}

char			*conversion(char *fmt, va_list args, char **segment)
{
	t_spec		conv_spec;
	int			conv;
	char		*str;

	if ((conv = parsing(fmt, &conv_spec, segment)) == -1)
		return (NULL);
	if (!(str = (*g_convert[conv])(args, &conv_spec)))
		return (NULL);
	return (str);
}
