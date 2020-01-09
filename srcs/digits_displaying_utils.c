/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_displaying_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:30:49 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 13:31:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_digit(unsigned long int d, int base, t_spec *spec)
{
	int			len;
	long int	tmp;

	if (!d)
		return (1);
	len = 1;
	if (spec->conv == 'd' || spec->conv == 'i')
	{
		tmp = (int)d;
		while (tmp /= base)
			len++;
	}
	else if (spec->conv == 'u' || spec->conv == 'x' ||
		spec->conv == 'X' || spec->conv == 'p')
	{
		if (spec->conv != 'p')
			d = (unsigned int)d;
		while (d /= base)
			len++;
	}
	else
		return (-1);
	return (len);
}

void	put_s_int_buffer(int nbr, t_printf *pf, t_spec *spec)
{
	unsigned int	nb;

	nb = nbr < 0 ? -nbr : nbr;
	if (nb >= 10)
	{
		put_s_int_buffer(nb / 10, pf, spec);
		write_in_buff_and_increment(pf, spec, (nb % 10) + '0');
	}
	else
		write_in_buff_and_increment(pf, spec, nb + '0');
}

void	put_u_int_buffer(unsigned int nb, t_printf *pf, t_spec *spec)
{
	if (nb >= 10)
	{
		put_u_int_buffer(nb / 10, pf, spec);
		write_in_buff_and_increment(pf, spec, nb % 10 + '0');
	}
	else
		write_in_buff_and_increment(pf, spec, nb + '0');
}

void	put_hexa_buffer(uintmax_t nb, t_printf *pf, t_spec *spec, char base[16])
{
	if (nb >= 16)
	{
		put_hexa_buffer(nb / 16, pf, spec, base);
		write_in_buff_and_increment(pf, spec, base[nb % 16]);
	}
	else
		write_in_buff_and_increment(pf, spec, base[nb]);
}
