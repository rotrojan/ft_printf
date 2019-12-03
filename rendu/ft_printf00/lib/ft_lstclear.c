/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:32:34 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/28 09:58:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;
	t_list		*next_link;

	if (*lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			next_link = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = next_link;
		}
		*lst = NULL;
	}
}
