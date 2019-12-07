/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:58:20 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/07 18:37:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	expand_buff(char **buf)
{
	static int		count = 1;
	char			*tmp;

	tmp = (char*)malloc((sizeof(tmp) * BUFFER_SIZE) * ++count);
	ft_bzero(tmp, BUFFER_SIZE * count);
	ft_memcpy(tmp, *buf, BUFFER_SIZE * (count - 1));
	free(*buf);
	*buf = tmp;
}

int		init_pf(t_printf *pf, char **format)
{
	ft_bzero(pf, sizeof(pf));
	pf->fmt = *format;
	if (!(pf->buf = (char*)malloc(sizeof(pf->buf) * BUFFER_SIZE)))
		return (0);
	ft_bzero(pf->buf, BUFFER_SIZE);
	pf->i_fmt = 0;
	pf->i_buf = 0;
	return (1);
}

int				ft_printf(char const *format, ...)
{
	va_list		args;
	t_printf	pf;

	va_start(args, format);
	if (!(init_pf(&pf, (char**)&format)))
		return (-1);
	while (pf.fmt[pf.i_fmt])
	{
		if (pf.fmt[pf.i_fmt] != '%')
		{
			pf.buf[pf.i_buf++] = pf.fmt[pf.i_fmt++];
			if (pf.i_buf == BUFFER_SIZE)
				expand_buff(&(pf.buf));
		}
		else
			ft_conversion(&pf, args);
	}
	va_end(args);
	return ((int)write(STDIN_FILENO, pf.buf, pf.i_buf));

}
