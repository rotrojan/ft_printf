/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/15 08:07:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define NB_CONVERSIONS 9
# define STR_CONVERSION "cspdiuxX%"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct	s_spec
{
	int		min_field_width;
	int		precision;
	int		padding;
	int		index_conv;
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

int				ft_printf(char const *format, ...);
void			print_buff_and_clear(t_printf *pf);
void			ft_conversion(t_printf *pf, va_list args);
void			parsing(t_printf *pf, t_spec *spec, va_list args, int *conv);

/*
*************************CONVERSION FUNCTIONS***********************************
*/

void			convert_char(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_str(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_ptr(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_int(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_uint(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_hexlow(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_hexupp(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_percent(t_printf *pf, t_spec *conv_spec, va_list args);

/*
******************************UTILS FUNCTIONS***********************************
*/

int				ft_atoi_lite(char const *str);
int				ft_isdigit(int c);
void			ft_bzero(void *b, size_t n);
size_t			ft_strlen(char const *str);

#endif
