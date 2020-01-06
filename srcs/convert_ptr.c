/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:23:59 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/06 22:52:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE 16

static void		left_padding(t_printf *pf, t_spec *spec, unsigned long int d)
{
	int		to_write;

	to_write = get_len_digit(d, BASE);
	write_in_buff_and_increment(pf, spec, '0');
	write_in_buff_and_increment(pf, spec, 'x');
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void	right_padding_fill(t_printf *pf, t_spec *spec, unsigned long int d, char c)
{
	int		to_write;

	to_write = get_len_digit(d, BASE);
	if (c == '0' && spec->precision != -1)
		c = ' ';
	if (c == '0')
	{
		write_in_buff_and_increment(pf, spec, '0');
		write_in_buff_and_increment(pf, spec, 'x');
	}
	while ((spec->width > to_write) && (spec->width > spec->precision))
	{
		if (d < 0 && (spec->width == to_write + 1
			|| spec->width == spec->precision + 1))
			break ;
		write_in_buff_and_increment(pf, spec, c);
	}
	if (c == ' ')
	{
		write_in_buff_and_increment(pf, spec, '0');
		write_in_buff_and_increment(pf, spec, 'x');
	}
	else if (d < 0 && spec->width > 0)
		write_in_buff_and_increment(pf, spec, '0');
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
}

static void		right_padding(t_printf *pf, t_spec *spec, unsigned long int d, char c)
{
	right_padding_fill(pf, spec, d, c);
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
		put_hexa_buffer(d, pf, spec, "0123456789abcdef");
}

void			convert_ptr(t_printf *pf, t_spec *spec, va_list args)
{
	int		d;
 
	d = va_arg(args, unsigned long int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
