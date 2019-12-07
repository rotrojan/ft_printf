/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/07 18:35:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../lib/libft.h"
# define NB_CONVERSIONS 8
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
	char		*buf;
	int			i_fmt;
	int			i_buf;

}				t_printf;

typedef enum	e_padding
{
	RIGHT_PADDING,
	ZERO_PADDING,
	LEFT_PADDING
}				t_padding;

/*************************FT_PRINTF FUNCTIONS**********************************/

int				ft_printf(char const *format, ...);
int				*ft_conversion(t_printf *pf, va_list args);
char			*convert_char(va_list args, t_spec *conv_spec);
int				ft_vasprintf(char **str, char const *format, va_list args);
void			parse_flags(char **fmt, t_spec *conv_spec);
int				parsing(char **segment, t_spec *conv_spec);

/************************CONVERSION FUNCTIONS**********************************/

int			*convert_str(va_list args, t_spec *conv_spec);
int			*convert_ptr(va_list args, t_spec *conv_spec);
int			*convert_int(va_list args, t_spec *conv_spec);
int			*convert_uint(va_list args, t_spec *conv_spec);
int			*convert_hexlow(va_list args, t_spec *conv_spec);
int			*convert_hexupp(va_list args, t_spec *conv_spec);
int			*convert_percent(va_list args, t_spec *conv_spec);

/*****************************UTILS FUNCTIONS**********************************/

int				ft_atoi(char const *str);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			*ft_memcpy(void *dst, void const *src, size_t n);
char			*ft_strdup(char const *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(char const *s);
int				ft_isdigit(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_bzero(void *b, size_t n);
char			*ft_memcat_free(char *s1, size_t size_s1, char *s2, size_t size_s2);

#endif
