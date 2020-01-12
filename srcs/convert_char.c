/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 10:10:45 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** All the conversions functions are build on the same pattern : the function
** uses va_arg to get the corresponding argument in the proper type, and then
** calls one of the two sub-functions dedicated to handle (namely) either the
** "right_padding" (with the specified padding character, '0' or ' ') or the
** "left_padding".
** If the '%%' conversion is performed, instead of geting the argument from
** va_arg, the char to print is considered to be '%'.
*/

static void		left_padding(t_printf *pf, t_spec *spec, char to_write)
{
	write_in_buff_and_increment(pf, spec, to_write);
	while (spec->width > 0)
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

	to_write = spec->conv == '%' ? '%' : (char)va_arg(args, int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, to_write);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, to_write, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, to_write, ' ');
}
