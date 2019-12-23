/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:21:50 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/22 17:32:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		left_padding(t_printf *pf, t_spec *spec, char *str)
{
	if (spec->precision == -1)
		while (*str)
		{
			pf->buf[pf->i_buf] = *str++;
			if (++pf->i_buf == BUFFER_SIZE)
				print_buff_and_clear(pf);
			spec->width--;
		}
	else
		while (*str && spec->precision-- > 0)
		{
			pf->buf[pf->i_buf] = *str++;
			if (++(pf->i_buf) == BUFFER_SIZE)
				print_buff_and_clear(pf);
			spec->width--;
		}
	while (spec->width > 0)
	{
		pf->buf[pf->i_buf] = ' ';
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
		spec->width--;
	}
}

static void		right_padding(t_printf *pf, t_spec *spec, char *str, char c)
{
	int		to_be_written;

	if (spec->precision == -1)
		to_be_written = ft_strlen(str);
	else
		to_be_written = ft_strlen(str) < spec->precision ?
			ft_strlen(str) : spec->precision;
	while (spec->width-- > to_be_written)
	{
		pf->buf[pf->i_buf] = c;
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
	while (to_be_written-- > 0)
	{
		pf->buf[pf->i_buf] = *str++;
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
}

void			convert_str(t_printf *pf, t_spec *spec, va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	if (str != NULL)
	{
		if (spec->padding == LEFT_PADDING)
			left_padding(pf, spec, str);
		else if (spec->padding == ZERO_PADDING)
			right_padding(pf, spec, str, '0');
		else if (spec->padding == RIGHT_PADDING)
			right_padding(pf, spec, str, ' ');
	}
	else
	{
		if (spec->padding == LEFT_PADDING)
			left_padding(pf, spec, "(null)");
		else if (spec->padding == ZERO_PADDING)
			right_padding(pf, spec, "(null)", '0');
		else if (spec->padding == RIGHT_PADDING)
			right_padding(pf, spec, "(null)", ' ');
	}
}
