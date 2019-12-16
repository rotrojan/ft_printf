/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/16 17:45:51 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**static void	test_disp_struc(t_spec *conv_spec)
**{
**	printf("width %d\n", conv_spec->min_field_width);
**	printf("precis %d\n", conv_spec->precision);
**	printf("paddin %d\n", conv_spec->padding);
**	printf("index_conv %d\n", conv_spec->index_conv);
**}
*/

void		init_spec(t_spec *spec)
{
	spec->min_field_width = -1;
	spec->precision = -1;
	spec->padding = RIGHT_PADDING;
}

void		ft_conversion(t_printf *pf, va_list args)
{
	t_spec			spec;
	int				index_conv;
	static void		(*convert[NB_CONVERSIONS])(t_printf*, t_spec*, va_list) = {
		&convert_char,
		&convert_str,
		&convert_ptr,
		&convert_int,
		&convert_int,
		&convert_uint,
		&convert_hexlow,
		&convert_hexupp,
		&convert_percent
	};

	index_conv = -1;
	init_spec(&spec);
	pf->i_fmt++;
	parsing(pf, &spec, args, &index_conv);
	convert[index_conv](pf, &spec, args);
}
