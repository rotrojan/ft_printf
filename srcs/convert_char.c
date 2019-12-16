/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/16 14:24:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		left_padding(t_printf *pf, t_spec *spec, va_list args)
{
	pf->buf[pf->i_buf] = (char)va_arg(args, int);
	spec->min_field_width--;
	if (++(pf->i_buf) == BUFFER_SIZE)
		print_buff_and_clear(pf);
	while (--spec->min_field_width >= 0)
	{
		pf->buf[pf->i_buf] = ' ';
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
}

static void		right_padding(t_printf *pf, t_spec *spec, va_list args, char c)
{
	while (spec->min_field_width-- > 1)
	{
		pf->buf[pf->i_buf] = c;
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
	pf->buf[pf->i_buf] = (char)va_arg(args, int);
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
}

void			convert_char(t_printf *pf, t_spec *spec, va_list args)
{
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, args);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, args, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, args, ' ');
}
