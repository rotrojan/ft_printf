/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:58:20 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/03 04:59:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_vasprintf(char **str, char const *format, va_list args)
{
	char	*tmp;
	char	*current;
	char	*segment;

	current = (char*)format;
	segment = (char*)format;
	while (*current)
	{
		if (*current != '%')
			current++;
		else
		{
			tmp = ft_substr(format, segment - format, segment - current);
			if (!(*str = ft_strjoin(*str, tmp)))
				return (-1);
			free(tmp);
			if (!(tmp = conversion(current, args, &segment)))
				return (-1);
			if (!(*str = ft_strjoin(*str, tmp)))
				return (-1);
			free(tmp);
		}
	}
	return (ft_strlen(*str));
}

int		ft_printf(char const *format, ...)
{
	va_list		args;
	char		*str;
	int			ret;
	char *yolo = "yolo";

	str = NULL;
	va_start(args, format);
	if ((ret = ft_vasprintf(&str, format, args)) != -1)
	{
		ft_putstr_fd(str, STDIN_FILENO);
		free(str);
	}
	va_end(args);
	return (ret);

}
