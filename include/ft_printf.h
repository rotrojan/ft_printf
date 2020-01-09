/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 01:44:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define NB_CONVERSIONS 9
# define STR_CONVERSION "cspdiuxX%"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_UINT 4294967295
# define MIN_UINT 0
#define MIN_LONG_LONG -9223372036854775807
#define MAX_LONG_LONG 9223372036854775807

typedef struct	s_spec
{
	int		width;
	int		precision;
	int		padding;
	char	conv;
}				t_spec;

typedef struct	s_printf
{
	char		*fmt;
	char		buf[BUFFER_SIZE];
	int			i_fmt;
	int			i_buf;
	int			already_written;
}				t_printf;

typedef enum	e_padding
{
	RIGHT_PADDING,
	ZERO_PADDING,
	LEFT_PADDING
}				t_padding;

/*
**************************FT_PRINTF FUNCTIONS***********************************
*/

int		ft_printf(char const *format, ...);
void	ft_conversion(t_printf *pf, va_list args);
void	parsing(t_printf *pf, t_spec *spec, va_list args, int *conv);
void	init_spec(t_spec *spec);
void	write_in_buff_and_increment(t_printf *pf, t_spec *spec, char c);

/*
*************************CONVERSION FUNCTIONS***********************************
*/

void	convert_char(t_printf *pf, t_spec *conv_spec, va_list args);
void	convert_str(t_printf *pf, t_spec *conv_spec, va_list args);
void	convert_ptr(t_printf *pf, t_spec *conv_spec, va_list args);
void	convert_int(t_printf *pf, t_spec *conv_spec, va_list args);
void	convert_uint(t_printf *pf, t_spec *conv_spec, va_list args);
void	convert_hexa(t_printf *pf, t_spec *conv_spec, va_list args);

/*
******************************UTILS FUNCTIONS***********************************
*/

int		get_len_digit(unsigned long int d, int base, t_spec *spec);
void	print_buff_and_clear(t_printf *pf);
void	put_s_int_buffer(int nb, t_printf *pf, t_spec *spec);
void	put_u_int_buffer(unsigned int nb, t_printf *pf, t_spec *spec);
void	put_hexa_buffer(uintmax_t nb, t_printf *pf, t_spec *spec, char base[16]);

/*
*******************************LIB FUNCTIONS************************************
*/

int			ft_atoi_lite(char const *str);
int			ft_isdigit(int c);
void		ft_bzero(void *b, size_t n);
int			ft_strlen(char const *str);

#endif
