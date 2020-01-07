/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:54:33 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/07 21:48:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		get_len_digit_signed(intmax_t d)
{
	int		len;

	if (!d)
		return (1);
	if (d == MIN_LONG_LONG)
		return (19);
	len = 1;
	while (d /= 10)
		len++;
	return (len);
}

int		get_len_digit_unsigned(uintmax_t d, int base)
{
	int		len;

	if (!d)
		return (1);
	if (d > MAX_INT && base == 16)
		return (8);
	len = 1;
	while (d /= base)
		len++;
//	printf("len = %d\n", len);
	return (len);
}

void			write_in_buff_and_increment(t_printf *pf, t_spec *spec, char c)
{
	pf->buf[pf->i_buf] = c;
	if (++pf->i_buf == BUFFER_SIZE)
		print_buff_and_clear(pf);
	spec->width--;
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

void	put_u_int_buffer(uintmax_t nbr, t_printf *pf, t_spec *spec)
{
	long int nb;

	nb = (unsigned int)nbr;
	if (nb >= 10)
	{
		put_u_int_buffer(nb / 10, pf, spec);
		write_in_buff_and_increment(pf, spec, nb % 10 + '0');
	}
	else
		write_in_buff_and_increment(pf, spec, nb + '0');
}

void
	put_hexa_buffer(uintmax_t nbr, t_printf *pf, t_spec *spec, char base[16])
{
	unsigned long long int nb;
	
	if (nbr <= MAX_LONG_LONG)
		nb = (unsigned long int)nbr;
	else
		nb = (unsigned long long int)nbr;
	if (nb >= 16)
	{
		put_hexa_buffer(nb / 16, pf, spec, base);
		write_in_buff_and_increment(pf, spec, base[nb % 16]);
	}
	else
		write_in_buff_and_increment(pf, spec, base[nb]);
}
