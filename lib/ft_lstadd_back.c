/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 10:46:57 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/28 09:36:37 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (new)
	{
		if (!*alst)
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			ft_lstlast(*alst)->next = new;
			new->next = NULL;
		}
	}
}
