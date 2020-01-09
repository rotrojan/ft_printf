/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:23:59 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 01:54:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE 16

static void		left_padding(t_printf *pf, t_spec *spec, uintptr_t d)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	write_in_buff_and_increment(pf, spec, '0');
	write_in_buff_and_increment(pf, spec, 'x');
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!(!d && !spec->precision && spec->width))
//		write_in_buff_and_increment(pf, spec, ' ');
//	else if (d || spec->precision)
	{
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
	}
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

#include <stdio.h>

static void		right_padding(t_printf *pf, t_spec *spec, uintptr_t d, char c)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	c = (c == '0' && spec->precision != -1) ? ' ' : c;
	if (c == ' ' && spec->precision != -1)
	{
		write_in_buff_and_increment(pf, spec, '0');
		write_in_buff_and_increment(pf, spec, 'x');
	}
	while ((spec->width > to_write) && (spec->width > spec->precision))
	{
		write_in_buff_and_increment(pf, spec, c);
		if ((spec->width == to_write + 2) && !(c == ' ' && spec->precision != -1))
			break ;
	}
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!(c == ' ' && spec->precision != -1))
	{
		write_in_buff_and_increment(pf, spec, '0');
		write_in_buff_and_increment(pf, spec, 'x');
	}
	if (!(!d && !spec->precision && spec->width))
//		write_in_buff_and_increment(pf, spec, ' ');
//	else
//	if (d || spec->precision)
	{
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
	}
}

void			convert_ptr(t_printf *pf, t_spec *spec, va_list args)
{
	uintptr_t		d;

	d = (uintptr_t)va_arg(args, void*);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
