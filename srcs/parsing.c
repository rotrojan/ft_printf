/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:59:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 08:29:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The "parsing" function will run the "parse_spec" function on each characters
** of the format string until the "is_token" function stops returning -1 (hence,
** when a conversion token is encountered).
** The "parse_flags" function will check for the padding ('0' or '-'), and the
** "parse_numbers_or_star" function will handle the minimum field width and the
** precision ('.'), either they come from the format string or from an extra
** argument ('*').
*/

static int	is_token(char c)
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

static int	parse_flags(t_printf *pf, t_spec *spec)
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

static void	parse_numbers_or_star(t_printf *pf, t_spec *spec, va_list args)
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
}

static int	parse_spec(t_printf *pf, t_spec *spec, va_list args)
{
	if (parse_flags(pf, spec))
		return (1);
	if (pf->fmt[pf->i_fmt] == '.')
	{
		pf->i_fmt++;
		parse_numbers_or_star(pf, spec, args);
		return (1);
	}
	if ((ft_isdigit(pf->fmt[pf->i_fmt]) && pf->fmt[pf->i_fmt] != '0')
		|| (pf->fmt[pf->i_fmt] == '*'))
	{
		parse_numbers_or_star(pf, spec, args);
		return (1);
	}
	return (0);
}

int			parsing(t_printf *pf, t_spec *spec, va_list args, int *index_conv)
{
	while ((*index_conv = is_token(pf->fmt[pf->i_fmt])) == -1)
	{
		if (!parse_spec(pf, spec, args))
		{
			ft_bzero(spec, sizeof(*spec));
			init_spec(spec);
			return (0);
		}
	}
	spec->conv = pf->fmt[pf->i_fmt];
	return (1);
}
