/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/07 18:39:25 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** void	test_disp_struc(t_spec *conv_spec)
** {
** printf("width %d\n", conv_spec->min_field_width);
** printf("precis %d\n", conv_spec->precision);
** printf("paddin %d\n", conv_spec->padding);
** }
*/

void		parse_flags(char **segment, t_spec *conv_spec)
{
	conv_spec->min_field_width = 0;
	conv_spec->precision = 0;
	conv_spec->padding = RIGHT_PADDING;
	(*segment)++;
	while (**segment == '-' || **segment == '0')
	{
		if (conv_spec->padding == RIGHT_PADDING)
		{
			if (**segment == '-')
				conv_spec->padding = LEFT_PADDING;
			else if (**segment == '0')
				conv_spec->padding = ZERO_PADDING;
		}
		else if (conv_spec->padding == ZERO_PADDING)
			if (**segment == '-')
				conv_spec->padding = LEFT_PADDING;
		(*segment)++;
	}
}

int			parsing(char **segment, t_spec *conv_spec)
{
	char	*token;

	token = NULL;
	parse_flags(segment, conv_spec);
	conv_spec->min_field_width = ft_atoi(*segment);
	while (ft_isdigit(**segment))
		(*segment)++;
	if (**segment == '.')
	{
		conv_spec->precision = ft_atoi(++(*segment));
		while (ft_isdigit(**segment))
			(*segment)++;
	}
	if (!(token = ft_strchr(str_conversion, **segment)))
		return (-1);
	(*segment)++;
	return (token - str_conversion);
}

int		*ft_conversion(t_printf *pf, va_list args)
{
	t_spec			conv_spec;
	int				conv;
	static char		*str_conversion = "cspdiuxX%";
	static char		*(*g_convert[NB_CONVERSIONS])(va_list, t_spec*) = {
		&convert_char,
		&convert_str,
		&convert_ptr,
		&convert_int,
		&convert_uint,
		&convert_hexlow,
		&convert_hexupp,
		&convert_percent
	};

	if ((conv = parsing(segment, &conv_spec)) == -1)
		return (NULL);
	if (!(str = (*g_convert[conv])(args, &conv_spec)))
		return (NULL);
//	(*segment)++;
	return (str);
}
