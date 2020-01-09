/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:58:20 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 11:53:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
