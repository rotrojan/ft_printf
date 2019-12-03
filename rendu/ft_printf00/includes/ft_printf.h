/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/03 05:09:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define NB_CONVERSIONS 9
# define STR_CONVERSIONS "cspdiuxX%"
# define STR_FLAGS "-0"

typedef struct	s_spec
{
	int		min_field_width;
	int		precision;
	int		padding;
	int		len_spec;
}			t_spec;

typedef enum	e_padding
{
			RIGHT_PADDING,
			ZERO_PADDING,
			LEFT_PADDING
}			t_padding;

int				ft_printf(char const *format, ...);
void			ft_putstr_fd(char const *str, int fd);
char			*ft_itoa(int n);
int				ft_strlen(char const *str);
char			*ft_substr(char const *s, int start, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar_fd(char c);
char			*conversion(char *conv_spec, va_list args, char **segment);
char			*convert_char(va_list args, t_spec conv_spec);
char			*convert_str(va_list args, t_spec conv_spec);
char			*convert_ptr(va_list args, t_spec conv_spec);
char			*convert_int(va_list args, t_spec conv_spec);
char			*convert_uint(va_list args, t_spec conv_spec);
char			*convert_hexlow(va_list args, t_spec conv_spec);
char			*convert_hexupp(va_list args, t_spec conv_spec);
char			*convert_percent(va_list args, t_spec conv_spec);
char			*ft_strchr(char const *, int c);
int				ft_atoi(char const *str);
int				ft_isdigit(int c);

char			g_str_conversion[10] = "cspdiuxX%";

char*			(*g_convert[NB_CONVERSIONS])(va_list, t_spec) = 
{
	&convert_char,
	&convert_str,
	&convert_ptr,
	&convert_int,
	&convert_uint,
	&convert_hexlow,
	&convert_hexupp,
	&convert_percent
};

/*
typedef struct	s_conversion
{
	char	token;
	int		(*fun_ptr)(va_list);
}				t_conversion;
*/

/*
t_conversion	g_jump_table[NB_CONVERSIONS] =
{
	{
		g_jump_table[0].token = 'c',
		g_jump_table[0].fun_ptr = &display_char
	},
	{
		g_jump_table[1].token = 's',
		g_jump_table[1].fun_ptr = &display_str
	},
	{
		g_jump_table[2].token = 'p',
		g_jump_table[2].fun_ptr = &display_ptr
	},
	{
		g_jump_table[3].token = 'd',
		g_jump_table[3].fun_ptr = &display_int
	},
	{
		g_jump_table[4].token = 'i',
		g_jump_table[4].fun_ptr = &display_int
	},
	{
		g_jump_table[5].token = 'u',
		g_jump_table[5].fun_ptr = &display_uint
	},
	{
		g_jump_table[6].token = 'x',
		g_jump_table[6].fun_ptr = &display_hexlow
	},
	{
		g_jump_table[7].token = 'X',
		g_jump_table[7].fun_ptr = &display_hexupp
	},
	{
		g_jump_table[8].token = '%',
		g_jump_table[8].fun_ptr = &display_percent
	}
};
*/

#endif
