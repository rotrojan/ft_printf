/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:04:46 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/19 21:18:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_buffer(int nb, t_printf *pf, t_spec *spec)
{
	if (nb < 0)
	{
		if (nb != -2147483648)
			nb = -nb;
		else
		{
			write_in_buff_and_increment(pf, spec, '2');
			nb = 147483648;
		}
	}
	if (nb >= 10)
	{
		putnbr_buffer(nb / 10, pf, spec);
		write_in_buff_and_increment(pf, spec, nb % 10 + '0');
	}
	else
		write_in_buff_and_increment(pf, spec, nb + '0');
}
