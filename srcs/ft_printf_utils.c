/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:54:33 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 13:42:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buff_and_clear(t_printf *pf)
{
	write(STDOUT_FILENO, pf->buf, BUFFER_SIZE);
	ft_bzero(pf->buf, BUFFER_SIZE);
	pf->i_buf = 0;
	pf->already_written += BUFFER_SIZE;
}

void	write_in_buff_and_increment(t_printf *pf, t_spec *spec, unsigned char c)
{
	pf->buf[pf->i_buf] = c;
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
	spec->width--;
}

void	init_spec(t_spec *spec)
{
	spec->width = 0;
	spec->precision = -1;
	spec->padding = RIGHT_PADDING;
}
