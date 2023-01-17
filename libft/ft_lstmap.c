/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:36:35 by obahi             #+#    #+#             */
/*   Updated: 2022/10/23 16:27:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = 0;
	node = 0;
	while (lst && f && del)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
			ft_lstclear(&head, del);
		ft_lstadd_back(&head, node);
		lst = lst -> next;
	}
	return (head);
}
