/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:23:46 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/06 17:11:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		left_padding(t_printf *pf, t_spec *spec)
{
	pf->buf[pf->i_buf] = '%';
	spec->width--;
	if (++(pf->i_buf) == BUFFER_SIZE)
		print_buff_and_clear(pf);
	while (--spec->width >= 0)
	{
		pf->buf[pf->i_buf] = ' ';
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
}

static void		right_padding(t_printf *pf, t_spec *spec, char c)
{
	while (spec->width-- > 1)
	{
		pf->buf[pf->i_buf] = c;
		if (++pf->i_buf == BUFFER_SIZE)
			print_buff_and_clear(pf);
	}
	pf->buf[pf->i_buf] = '%';
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
}

void			convert_percent(t_printf *pf, t_spec *spec, va_list args)
{
	(void)args;
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, ' ');
}
