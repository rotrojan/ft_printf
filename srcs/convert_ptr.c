/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:23:59 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 10:15:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE 16

/*
** All the conversions functions are build on the same pattern : the function
** uses va_arg to get the corresponding argument in the proper type, and then
** calls one of the two sub-functions dedicated to handle (namely) either the
** "right_padding" (with the specified padding character, '0' or ' ') or the
** "left_padding".
** The addresses are always written in a lower case hexadecimal base and are
** prefixed with "0x".
*/

static void		put_zero_x_in_front_of_address(t_printf *pf, t_spec *spec)
{
	write_in_buff_and_increment(pf, spec, '0');
	write_in_buff_and_increment(pf, spec, 'x');
}

static void		left_padding(t_printf *pf, t_spec *spec, uintptr_t d)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	put_zero_x_in_front_of_address(pf, spec);
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (d || spec->precision || !spec->width)
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void		right_padding(t_printf *pf, t_spec *spec, uintptr_t d, char c)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	c = (c == '0' && spec->precision != -1) ? ' ' : c;
	while ((spec->width > to_write + 2) && (spec->width > spec->precision + 2))
		write_in_buff_and_increment(pf, spec, c);
	put_zero_x_in_front_of_address(pf, spec);
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (d || spec->precision || !spec->width)
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
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
