/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:58:20 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/16 14:24:38 by rotrojan         ###   ########.fr       */
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

int		ft_printf(char const *format, ...)
{
	va_list		args;
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fmt = (char*)format;
	va_start(args, format);
	while (pf.fmt[pf.i_fmt])
	{
		if (pf.fmt[pf.i_fmt] != '%')
		{
			pf.buf[pf.i_buf++] = pf.fmt[pf.i_fmt++];
			if (pf.i_buf == BUFFER_SIZE)
				print_buff_and_clear(&pf);
		}
		else
		{
			ft_conversion(&pf, args);
			pf.i_fmt++;
		}
	}
	va_end(args);
	write(STDOUT_FILENO, pf.buf, pf.i_buf);
	return (pf.i_buf + pf.already_written);
}
