/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:52:41 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 00:05:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE 16

static void		left_padding(t_printf *pf, t_spec *spec, uintmax_t d)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
	{
		if (spec->conv == 'x')
			put_hexa_buffer(d, pf, spec, "0123456789abcdef");
		else if (spec->conv == 'X')
			put_hexa_buffer(d, pf, spec, "0123456789ABCDEF");
	}
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void		right_padding(t_printf *pf, t_spec *spec, uintmax_t d, char c)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	if (c == '0' && spec->precision != -1)
		c = ' ';
	while ((spec->width > to_write) && (spec->width > spec->precision))
		write_in_buff_and_increment(pf, spec, c);
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
	{
		if (spec->conv == 'x')
			put_hexa_buffer(d, pf, spec, "0123456789abcdef");
		else if (spec->conv == 'X')
			put_hexa_buffer(d, pf, spec, "0123456789ABCDEF");
	}
}

#include <stdio.h>

void			convert_hexa(t_printf *pf, t_spec *spec, va_list args)
{
	uintmax_t	d;

	d = va_arg(args, uintmax_t);
//	printf("d =  %lx\n", d);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
