/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:59:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 16:36:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_token(char c)
{
	static char const		*str_conversion = STR_CONVERSION;
	char					*current;

	current = (char*)str_conversion;
	while (*current)
	{
		if (*current == c)
			return ((int)(current - str_conversion));
		current++;
	}
	return (-1);
}

int			parse_flags(t_printf *pf, t_spec *spec)
{
	if (pf->fmt[pf->i_fmt] == '-')
	{
		spec->padding = LEFT_PADDING;
		pf->i_fmt++;
		return (1);
	}
	else if (pf->fmt[pf->i_fmt] == '0')
	{
		if (spec->padding != LEFT_PADDING)
			spec->padding = ZERO_PADDING;
		pf->i_fmt++;
		return (1);
	}
	else
		return (0);
}

#include <stdio.h>

void		parse_numbers_or_star(t_printf *pf, t_spec *spec, va_list args)
{
	if (pf->fmt[pf->i_fmt] == '*' && (pf->fmt[pf->i_fmt - 1] == '.'))
	{
		spec->precision = va_arg(args, int);
		pf->i_fmt++;
	}
	else if (pf->fmt[pf->i_fmt] == '*')
	{
		spec->width = va_arg(args, int);
		pf->i_fmt++;
	}
	else if (pf->fmt[pf->i_fmt - 1] == '.')
		spec->precision = ft_atoi_lite(&pf->fmt[pf->i_fmt]);
	else
		spec->width = ft_atoi_lite(&pf->fmt[pf->i_fmt]);
	while (ft_isdigit(pf->fmt[pf->i_fmt]))
		pf->i_fmt++;
	if (spec->width < 0)
	{
		spec->width *= -1;
		spec->padding = LEFT_PADDING;
	}
	spec->precision = spec->precision < 0 ? -1 : spec->precision;
//	printf("\nprecision = %d\nwidth = %d\n", spec->precision, spec->width);
}

void		parse_spec(t_printf *pf, t_spec *spec, va_list args)
{
	if (parse_flags(pf, spec))
		return ;
	if (pf->fmt[pf->i_fmt] == '.')
	{
		pf->i_fmt++;
		parse_numbers_or_star(pf, spec, args);
		return ;
	}
	if ((ft_isdigit(pf->fmt[pf->i_fmt]) && pf->fmt[pf->i_fmt] != '0')
		|| (pf->fmt[pf->i_fmt] == '*'))
	{
		parse_numbers_or_star(pf, spec, args);
		return ;
	}
}

void		parsing(t_printf *pf, t_spec *spec, va_list args, int *index_conv)
{
	int		index_beggin_parsing;

	index_beggin_parsing = pf->i_fmt;
	while ((*index_conv = is_token(pf->fmt[pf->i_fmt])) == -1)
	{
		if (!pf->fmt[pf->i_fmt])
		{
			ft_bzero(spec, sizeof(*spec));
			init_spec(spec);
			pf->i_fmt = index_beggin_parsing;
			break ;
		}
		parse_spec(pf, spec, args);
	}
	spec->conv = pf->fmt[pf->i_fmt];
}
