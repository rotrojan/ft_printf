/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/08 23:10:13 by rotrojan         ###   ########.fr       */
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

int		is_token(t_printf *pf)
{
	char	*str_conversion;

	while (*str_conversion)
	{
		if (pf->fmt[pf->i_fmt] == *str_conversion)
			return (1);
		str_conversion++;
	}
	return (0);
}

void		parsing(t_printf *pf, t_spec *spec, va_list args)
{
	while (pf->fmt[pf->i_fmt])
	{
		
	}
}

void		ft_conversion(t_printf *pf, va_list args)
{
	t_spec			spec;
	int				conv;
	static char		*str_conversion = STR_CONVERSION;
	static int		*(*convert[NB_CONVERSIONS])(t_printf*, t_spec*, va_list) =
	{
		&convert_char,
		&convert_str,
		&convert_ptr,
		&convert_int,
		&convert_uint,
		&convert_hexlow,
		&convert_hexupp,
		&convert_percent
	};

	pf->i_fmt++;
	parsing(pf, &spec, args);
	conv = 0;
	while (conv < NB_CONVERSIONS)
	{
		if (str_conversion[conv] == pf->fmt[pf->i_fmt])
			(convert)[conv](pf, &spec, args);
		conv++;
	}
}
