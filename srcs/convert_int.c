/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:22:06 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/18 11:28:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		right_padding(t_printf *pf, t_spec *spec, int d, char c)
{
	while ()
	{
		
	}
}

static void		left_padding(t_printf *pf, t_spec *spec, int d)
{

}

static int		get_len_digit(int d)
{
	int		len;

	if (!d)
		return (1);
	if (d < 0)
		len = 2;
	else
		len = 1;
	while (d /= 10)
		len++;
	return (len);
}

void			convert_int(t_printf *pf, t_spec *spec, va_list args)
{
	int		d;

	d = va_arg(args, int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
