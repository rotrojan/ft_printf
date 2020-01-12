/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:33:39 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 09:58:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** A function pointer array is declared (staticly, since it will be be reused
** for all potential further conversions) containing pointers to all the
** conversions functions.
** A t_spec structure is also declared to hold all the conversion specifications
** parsed (see the ft_printf.h header file for more informations).
** The index of the beggining of the parsing is kept in memory in case of a non
** existing conversion flag or token. If the parsing went well, the matching
** conversion function is called, else the function ends and the ft_printf
** function go back to "index_beggin_parsing".
*/

void	conversion(t_printf *pf, va_list args)
{
	t_spec			spec;
	int				index_conv;
	int				index_beggin_parsing;
	static void		(*convert[NB_CONVERSIONS])(t_printf*, t_spec*, va_list) = {
		&convert_char,
		&convert_str,
		&convert_ptr,
		&convert_int,
		&convert_int,
		&convert_uint,
		&convert_hexa,
		&convert_hexa,
		&convert_char
	};

	index_conv = -1;
	init_spec(&spec);
	index_beggin_parsing = pf->i_fmt++;
	if (!parsing(pf, &spec, args, &index_conv))
		pf->i_fmt = index_beggin_parsing;
	else
		convert[index_conv](pf, &spec, args);
}
