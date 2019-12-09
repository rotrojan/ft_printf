/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:53:34 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/09 22:27:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char const *str)
{
	int		result;
	char	is_negative;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	is_negative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + *(str++) - '0';
	return (result * is_negative);
}

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char		*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	while (n--)
		*tmp++ = *(unsigned char*)src++;
	return (dst);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

char	*ft_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (!c)
		return ((char*)s);
	return (NULL);
}

/*
char	*ft_strdup(char const *s1)
{
	char			*str;
	char			*tmp;

	if (!(str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *(unsigned char*)s1++;
	*tmp = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*tmp;

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
		return (ft_strdup(s1));
	if (!(str = (char*)malloc((sizeof(*tmp)
		* (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*tmp;
	char const		*cpy_s;
	size_t			maxlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		maxlen = 0;
	else
	{
		cpy_s = s;
		while (len-- && *cpy_s)
			cpy_s++;
		maxlen = (size_t)(cpy_s - s);
	}
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	tmp = str;
	cpy_s = s;
	while (maxlen--)
		*tmp++ = *(cpy_s++ + start);
	*tmp = '\0';
	return (str);
}

*/
size_t		ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)b;
	while (n--)
		*(unsigned char*)tmp++ = 0;
}
