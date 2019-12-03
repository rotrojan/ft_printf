/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:29 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/29 23:11:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
