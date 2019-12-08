/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/08 23:03:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define NB_CONVERSIONS 8
# define STR_CONVERSION "cspdiuxX%"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct	s_spec
{
	int		min_field_width;
	int		precision;
	int		padding;
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

/*************************FT_PRINTF FUNCTIONS**********************************/

int				ft_printf(char const *format, ...);
void			ft_conversion(t_printf *pf,  va_list args);
void			parsing(t_printf *pf, t_spec *spec, va_list args);

/************************CONVERSION FUNCTIONS**********************************/

int				*convert_char(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_str(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_ptr(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_int(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_uint(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_hexlow(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_hexupp(t_printf *pf, t_spec *conv_spec, va_list args);
int				*convert_percent(t_printf *pf, t_spec *conv_spec, va_list args);

/*****************************UTILS FUNCTIONS**********************************/

int				ft_atoi(char const *str);
void			*ft_memcpy(void *dst, void const *src, size_t n);
int				ft_isdigit(int c);
void			ft_bzero(void *b, size_t n);

#endif
