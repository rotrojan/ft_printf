/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:19:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/09 23:37:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		convert_char(t_printf *pf, t_spec *spec, va_list args)
{
	if (spec->padding == LEFT_PADDING)
	{
		pf->buf[pf->i_buf] = va_arg(args, int);
		if (++(pf->i_buf) == BUFFER_SIZE)
			print_buff_and_clear(pf);
		while (--(spec->min_field_width) >= 0)
		{
			pf->buf[pf->i_buf] = ' ';
			if (++(pf->i_buf) == BUFFER_SIZE)
				print_buff_and_clear(pf);
		}
	}
}
