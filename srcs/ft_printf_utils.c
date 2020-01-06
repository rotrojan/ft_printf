/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:54:33 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/06 22:35:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_digit(unsigned long int d, int base)
{
	int		len;

	if (!d)
		return (1);
	len = 1;
	while (d /= base)
		len++;
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

void
	put_hexa_buffer(unsigned long int nb, t_printf *pf, t_spec *spec, char base[16])
{
	if (nb >= 16)
	{
		put_hexa_buffer(nb / 16, pf, spec, base);
		write_in_buff_and_increment(pf, spec, base[nb % 16]);
	}
	else
		write_in_buff_and_increment(pf, spec, base[nb]);
}
