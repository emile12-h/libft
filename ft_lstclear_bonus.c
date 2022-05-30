/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:58:59 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:47:28 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*nxt;

	nxt = NULL;
	list = *lst;
	while (list != NULL)
	{
		nxt = list->next;
		del(list->content);
		free(list);
		list = nxt;
	}
	*lst = NULL;
}
