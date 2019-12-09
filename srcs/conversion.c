/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/09 23:40:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
static void	test_disp_struc(t_spec *conv_spec)
{
	printf("width %d\n", conv_spec->min_field_width);
	printf("precis %d\n", conv_spec->precision);
	printf("paddin %d\n", conv_spec->padding);
	printf("index_conv %d\n", conv_spec->index_conv);
}
*/

int		is_token(char c)
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
	else if (pf->fmt[pf->i_fmt] == '0' && spec->padding != LEFT_PADDING)
	{
		spec->padding = ZERO_PADDING;
		pf->i_fmt++;
		return (1);
	}
	else
		return (0);
}

void		parse_numbers_or_star(t_printf *pf, va_list args, int *spec_value)
{
	if (pf->fmt[pf->i_fmt] == '*')
	{
		*spec_value = va_arg(args, int);
		pf->i_fmt++;
	}
	else
	{
		*spec_value = ft_atoi(&pf->fmt[pf->i_fmt]);
		while (ft_isdigit(pf->fmt[pf->i_fmt]))
			pf->i_fmt++;
	}
}

void		parse_spec(t_printf *pf, t_spec *spec, va_list args)
{
	if (parse_flags(pf, spec))
		return ;
	if (pf->fmt[pf->i_fmt] == '.')
	{
		pf->i_fmt++;
		parse_numbers_or_star(pf, args, &(spec->precision));
		return ;
	}
	if ((ft_isdigit(pf->fmt[pf->i_fmt]) && pf->fmt[pf->i_fmt] != '0')
		|| (pf->fmt[pf->i_fmt] == '*'))
	{
		parse_numbers_or_star(pf, args, &(spec->min_field_width));
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
			pf->i_fmt = index_beggin_parsing;
			break ;
		}
		parse_spec(pf, spec, args);
	}
}

void		ft_conversion(t_printf *pf, va_list args)
{
	t_spec			spec;
	int				index_conv;
	static void		(*convert[NB_CONVERSIONS])(t_printf*, t_spec*, va_list) =
	{
		&convert_char,
/*		&convert_str,
		&convert_ptr,
		&convert_int,
		&convert_uint,
		&convert_uint,
		&convert_hexlow,
		&convert_hexupp,
		&convert_percent
*/	};

	ft_bzero(&spec, sizeof(spec));
	pf->i_fmt++;
	parsing(pf, &spec, args, &index_conv);
	convert[index_conv](pf, &spec, args);
//	test_disp_struc(&spec);
}
