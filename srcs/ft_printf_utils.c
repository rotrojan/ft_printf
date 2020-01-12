/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:54:33 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 09:34:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The "print_buff_and_clear" is pretty self-explained : once the buffer is
** full, it is printed and emptied, and the pf->already_written value is
** incremented of BUFFER_SIZE.
*/

void	print_buff_and_clear(t_printf *pf)
{
	write(STDOUT_FILENO, pf->buf, BUFFER_SIZE);
	ft_bzero(pf->buf, BUFFER_SIZE);
	pf->i_buf = 0;
	pf->already_written += BUFFER_SIZE;
}

/*
** Every and each single characters that will be put in the buffer via a
** conversion function will be so by the "write_in_buff_and_increment" function
** It will, as named, put the given character in the pf->buf buffer, increment
** the pf->i_fmt buffer index, and will decrement the spec->width (since we
** will have to keep track of this value all along the conversions).
*/

void	write_in_buff_and_increment(t_printf *pf, t_spec *spec, unsigned char c)
{
	pf->buf[pf->i_buf] = c;
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
	spec->width--;
}

/*
** The "init_spec" function initialize the t_spec struture. A b_zero is indeed
** not sufficient : the spec->precision must initialize to -1 because a zero-
** sized precision is not handled the same as no precision at all.
*/

void	init_spec(t_spec *spec)
{
	spec->width = 0;
	spec->precision = -1;
	spec->padding = RIGHT_PADDING;
}
