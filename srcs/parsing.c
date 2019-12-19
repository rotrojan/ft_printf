/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:59:24 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/19 10:40:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_token(char c)
{
	static char		*str_conversion = STR_CONVERSION;
	char			*current;

	current = str_conversion;
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

void		parse_numbers_or_star(t_printf *pf, t_spec *spec, va_list args)
{
	if (pf->fmt[pf->i_fmt] == '*')
	{
		if (pf->fmt[pf->i_fmt - 1] == '.')
		{
			if ((spec->precision = va_arg(args, int)) < 0)
				spec->precision = -1;
		}
		else
			spec->min_field_width = va_arg(args, int);
		pf->i_fmt++;
	}
	else
	{
		if (pf->fmt[pf->i_fmt - 1] == '.')
			spec->precision = ft_atoi_lite(&pf->fmt[pf->i_fmt]);
		else
			spec->min_field_width = ft_atoi_lite(&pf->fmt[pf->i_fmt]);
		while (ft_isdigit(pf->fmt[pf->i_fmt]))
			pf->i_fmt++;
	}
	if (spec->min_field_width < 0)
	{
		spec->min_field_width *= -1;
		spec->padding = LEFT_PADDING;
	}
	if (spec->precision < 0)
		spec->precision = -1;
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
}
