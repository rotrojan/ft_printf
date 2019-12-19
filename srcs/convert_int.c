/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:22:06 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/19 21:19:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_len_digit(int d)
{
	int		len;

	if (!d)
		return (1);
	len = 1;
	while (d /= 10)
		len++;
	return (len);
}

void			write_in_buff_and_increment(t_printf *pf, t_spec *spec, char c)
{
	pf->buf[pf->i_buf] = c;
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
	spec->min_field_width--;
}

static void		left_padding(t_printf *pf, t_spec *spec, int d)
{
	int		len_to_write;

	len_to_write = get_len_digit(d);
	if (d < 0)
		write_in_buff_and_increment(pf, spec, '-');
	while (spec->precision > len_to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision)
		write_in_buff_and_increment(pf, spec, ' ');
	else
		putnbr_buffer(d, pf, spec);
	while (spec->min_field_width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void		right_padding(t_printf *pf, t_spec *spec, int d, char c)
{
	int		len_to_write;

	len_to_write = get_len_digit(d);
	if (c == '0' && spec->precision != -1)
		c = ' ';
	if (d < 0 && c == '0')
		write_in_buff_and_increment(pf, spec, '-');
	while ((spec->min_field_width > len_to_write + 1) &&
		(spec->min_field_width > spec->precision + 1))
		write_in_buff_and_increment(pf, spec, c);
	if (d < 0 && c == ' ')
		write_in_buff_and_increment(pf, spec, '-');
	else
		write_in_buff_and_increment(pf, spec, c);
	while (spec->precision > len_to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision)
		write_in_buff_and_increment(pf, spec, ' ');
	else
		putnbr_buffer(d, pf, spec);
}

void			convert_int(t_printf *pf, t_spec *spec, va_list args)
{
	int		d;

	d = va_arg(args, int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
