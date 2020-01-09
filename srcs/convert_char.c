/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 02:49:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		left_padding(t_printf *pf, t_spec *spec, char to_write)
{
	write_in_buff_and_increment(pf, spec, to_write);
	while (spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void		right_padding(t_printf *pf, t_spec *spec, char to_write, char c)
{
	while (spec->width > 1)
		write_in_buff_and_increment(pf, spec, c);
	write_in_buff_and_increment(pf, spec, to_write);
}

void			convert_char(t_printf *pf, t_spec *spec, va_list args)
{
	char	to_write;

	to_write = spec->precision == '%' ? '%' : (char)va_arg(args, int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, to_write);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, to_write, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, to_write, ' ');
}
