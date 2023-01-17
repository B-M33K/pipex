/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:23:03 by obahi             #+#    #+#             */
/*   Updated: 2022/10/22 09:00:47 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (del && lst)
	{
		head = *lst;
		while (head)
		{
			tmp = head -> next;
			ft_lstdelone(head, del);
			head = tmp;
		}
		*lst = 0;
	}
}
